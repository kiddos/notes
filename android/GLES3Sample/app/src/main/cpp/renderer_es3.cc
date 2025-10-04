#include <EGL/egl.h>
#include <GLES3/gl32.h>
#include <cassert>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "renderer.h"
#include "gles3jni.h"

class RendererES3 : public Renderer {
public:
  explicit RendererES3(AAssetManager *assetManager);
  ~RendererES3() override;
  void resize(int w, int h) override;
  void draw() override;
  void onTouch(float dx, float dy) override;
  void drawTriangle();

private:
  EGLContext context_;
  GLuint program_;
  GLuint position_handle_;
  std::vector<Mesh> meshes_;
  glm::mat4 model_, view_, projection_;
};

std::vector<Mesh> LoadModelFromAssets(AAssetManager* mgr, const char* filename) {
  std::vector<Mesh> meshes;

  // Open asset
  AAsset* asset = AAssetManager_open(mgr, filename, AASSET_MODE_BUFFER);
  if (!asset) {
    LOGE("Failed to open asset: %s", filename);
    return meshes;
  }

  // Get buffer
  size_t length = AAsset_getLength(asset);
  const void* buffer = AAsset_getBuffer(asset);
  if (!buffer) {
    LOGE("Failed to get buffer for asset: %s", filename);
    AAsset_close(asset);
    return meshes;
  }

  // Import model from memory
  Assimp::Importer importer;
  const aiScene* scene = importer.ReadFileFromMemory(
      buffer,
      length,
      aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals,
      nullptr // let Assimp detect format automatically
  );

  if (!scene || !scene->HasMeshes()) {
    LOGE("Error loading model: %s", importer.GetErrorString());
    AAsset_close(asset);
    return meshes;
  }

  for (unsigned int m = 0; m < scene->mNumMeshes; ++m) {
    aiMesh* mesh = scene->mMeshes[m];
    Mesh myMesh;

    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
      Vertex v{};
      v.position[0] = mesh->mVertices[i].x;
      v.position[1] = mesh->mVertices[i].y;
      v.position[2] = mesh->mVertices[i].z;

      if (mesh->HasNormals()) {
        v.normal[0] = mesh->mNormals[i].x;
        v.normal[1] = mesh->mNormals[i].y;
        v.normal[2] = mesh->mNormals[i].z;
      }

      if (mesh->HasTextureCoords(0)) {
        v.texCoord[0] = mesh->mTextureCoords[0][i].x;
        v.texCoord[1] = mesh->mTextureCoords[0][i].y;
      } else {
        v.texCoord[0] = v.texCoord[1] = 0.0f;
      }

      myMesh.vertices.push_back(v);
    }

    for (unsigned int f = 0; f < mesh->mNumFaces; ++f) {
      aiFace face = mesh->mFaces[f];
      for (unsigned int j = 0; j < face.mNumIndices; ++j) {
        myMesh.indices.push_back(face.mIndices[j]);
      }
    }

    meshes.push_back(std::move(myMesh));
  }

  AAsset_close(asset);
  return meshes;
}
static void checkGlError(const char *op) {
  for (GLint error = glGetError(); error; error = glGetError()) {
    LOGI("after %s() glError (0x%x)\n", op, error);
  }
}

std::string LoadShaderFile(AAssetManager *assetManager, const char *file_path) {
  std::string file_content;
  assert(assetManager);
  LOGI("loading %s", file_path);

  AAsset *file = AAssetManager_open(assetManager, file_path, AASSET_MODE_BUFFER);
  size_t file_length = AAsset_getLength(file);

  file_content.resize(file_length);

  AAsset_read(file, file_content.data(), file_length);
  AAsset_close(file);
  return file_content;
}

GLuint loadShader(AAssetManager *assetManager, GLenum shaderType, const char *filename) {
  GLuint shader = glCreateShader(shaderType);

  auto shaderCode = LoadShaderFile(assetManager, filename);

  if (shader) {
    const char *source = shaderCode.c_str();
    LOGI("shader: %s", source);

    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    GLint compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
      GLint infoLen = 0;
      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
      if (infoLen) {
        char *buf = (char *) malloc(infoLen);
        if (buf) {
          glGetShaderInfoLog(shader, infoLen, NULL, buf);
          LOGE("Could not compile shaders %d:\n%s\n", shaderType, buf);
          free(buf);
        }
        glDeleteShader(shader);
        shader = 0;
      }
    }
  }
  return shader;
}

GLuint createProgram(AAssetManager *assetManager, const char *pVertexSource, const char *pFragmentSource) {
  GLuint vertexShader = loadShader(assetManager, GL_VERTEX_SHADER, pVertexSource);
  if (!vertexShader) {
    return 0;
  }

  GLuint pixelShader = loadShader(assetManager, GL_FRAGMENT_SHADER, pFragmentSource);
  if (!pixelShader) {
    return 0;
  }

  GLuint program = glCreateProgram();
  if (program) {
    glAttachShader(program, vertexShader);
    checkGlError("glAttachShader");
    glAttachShader(program, pixelShader);
    checkGlError("glAttachShader");
    glLinkProgram(program);
    GLint linkStatus = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) {
      GLint bufLength = 0;
      glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
      if (bufLength) {
        char *buf = (char *) malloc(bufLength);
        if (buf) {
          glGetProgramInfoLog(program, bufLength, NULL, buf);
          LOGE("Could not link program:\n%s\n", buf);
          free(buf);
        }
      }
      glDeleteProgram(program);
      program = 0;
    }
  }
  return program;
}

RendererES3::RendererES3(AAssetManager *assetManager) : context_(eglGetCurrentContext()) {
  program_ = createProgram(assetManager, "vertex.glsl", "fragment.glsl");
  position_handle_ = glGetAttribLocation(program_, "vPosition");
  checkGlError("glGetAttribLocation");

  glUseProgram(program_);
  checkGlError("glUseProgram");

  meshes_ = LoadModelFromAssets(assetManager, "teapot.obj");
  for (auto &mesh : meshes_) {
    mesh.setupMesh();
  }

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  // Enable backface culling
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);
}

RendererES3::~RendererES3() {
  if (eglGetCurrentContext() != context_) {
    return;
  }
  glDeleteProgram(program_);
}

void RendererES3::resize(int w, int h) {
  model_ = glm::mat4(1.0f); // identity or object transform
  view_ = glm::lookAt(
      glm::vec3(0.0f, 0.0f, 20.0f),  // camera position
      glm::vec3(0.0f, 0.0f, 0.0f),  // look at origin
      glm::vec3(0.0f, 1.0f, 0.0f)   // up vector
  );
  projection_ = glm::perspective(
      glm::radians(45.0f),
      (float)w / (float)h,
      0.1f, 100.0f
  );

  glViewport(0, 0, w, h);
}

void RendererES3::drawTriangle() {
  // draw a triangle here
  const GLfloat gTriangleVertices[] = {0.0f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f};

  glUseProgram(program_);
  glVertexAttribPointer(position_handle_, 2, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);
  glEnableVertexAttribArray(position_handle_);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RendererES3::draw() {
  glUseProgram(program_);

  GLint modelLoc = glGetUniformLocation(program_, "uModel");
  GLint viewLoc = glGetUniformLocation(program_, "uView");
  GLint projLoc = glGetUniformLocation(program_, "uProjection");

  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model_));
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view_));
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection_));

  for (auto &mesh : meshes_) {
    mesh.draw();
  }
}

void logMatrix(const glm::mat4 &mat, const char* name) {
  const float *m = glm::value_ptr(mat);
  LOGI("%s =", name);
  for (int i = 0; i < 4; i++) {
    LOGI("%f %f %f %f", m[i], m[4 + i], m[8 + i], m[12 + i]);
  }
}

void RendererES3::onTouch(float dx, float dy) {
  LOGI("delta = %f,%f", dx, dy);
  float angle_y = dx * 0.5;
  float angle_x = dy * 0.5;
  model_ = glm::rotate(model_, glm::radians(angle_x), glm::vec3(1, 0, 0));
  model_ = glm::rotate(model_, glm::radians(angle_y), glm::vec3(0, 1, 0));
  // logMatrix(model_, "Model");
}

std::unique_ptr<Renderer> createES3Renderer(AAssetManager *assetManager) {
  return std::make_unique<RendererES3>(assetManager);
}
#ifndef GLES3SAMPLE_RENDERER_H
#define GLES3SAMPLE_RENDERER_H

#include <cmath>
#include <memory>
#include <vector>
#include <android/asset_manager.h>
#include <GLES3/gl32.h>

struct Vertex {
  float position[3];
  float normal[3];
  float texCoord[2];
};

struct Mesh {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;

  GLuint vao = 0, vbo = 0, ebo = 0;

  void setupMesh() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    // Vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),
                 vertices.data(), GL_STATIC_DRAW);

    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
                 indices.data(), GL_STATIC_DRAW);

    // Position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

    // Normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    // TexCoord attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));

    glBindVertexArray(0);
  }

  void draw() {
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
  }
};

class Renderer {
public:
  Renderer();
  virtual ~Renderer();
  virtual void resize(int w, int h);
  virtual void onTouch(float dx, float dy) = 0;
  void render();
  virtual void draw() = 0;
};

std::unique_ptr<Renderer> createES3Renderer(AAssetManager *assetManager);

#endif //GLES3SAMPLE_RENDERER_H
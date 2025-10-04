#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <jni.h>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include <string>
#include <vector>
#include <cassert>
#include <memory>

#include "renderer.h"
#include "gles3jni.h"

static AAssetManager *assetManager = nullptr;
static std::unique_ptr<Renderer> renderer;

static void printGLString(const char *name, GLenum s) {
  const char *v = (const char *) glGetString(s);
  LOGI("GL %s = %s\n", name, v);
}

void LoadAssetManager(JNIEnv *env, jobject javaAssetManager) {
  LOGI("prepare asset manager");

  // get asset manager from java
  if (assetManager == nullptr) {
    assetManager = AAssetManager_fromJava(env, javaAssetManager);

    if (assetManager != nullptr) {
      LOGI("AssetManager successfully obtained and cached.");
    } else {
      LOGI("Failed to obtain AssetManager!");
    }
  }
}

void JNICALL Init(JNIEnv *env, jclass, jobject javaAssetManager) {
  LOGI("Init");

  printGLString("Version", GL_VERSION);
  printGLString("Vendor", GL_VENDOR);
  printGLString("Renderer", GL_RENDERER);
  printGLString("Extensions", GL_EXTENSIONS);

  LoadAssetManager(env, javaAssetManager);
  renderer = createES3Renderer(assetManager);
}

void JNICALL Resize(JNIEnv *, jclass, jint width, jint height) {
  LOGI("Resize (%d, %d)", width, height);
  renderer->resize(width, height);
}

void JNICALL Step(JNIEnv *, jclass) {
  if (renderer) {
    renderer->render();
  }
}

void JNICALL OnTouch(JNIEnv *, jclass, jfloat dx, jfloat dy) {
  if (renderer) {
    renderer->onTouch(dx, dy);
  }
}

// template way to get array size
template<typename T, size_t N>
char (&ArraySizeHelper(T (&array)[N]))[N];

extern "C" JNIEXPORT jint JNI_OnLoad(JavaVM *_Nonnull vm, void *_Nullable) {
  JNIEnv *env;
  if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
    return JNI_ERR;
  }

  jclass c = env->FindClass("app/kiddos/gles3sample/GLES3Lib");
  if (c == nullptr) {
    return JNI_ERR;
  }

  static const JNINativeMethod methods[] = {
      {"init",   "(Landroid/content/res/AssetManager;)V", reinterpret_cast<void *>(Init)},
      {"onTouch", "(FF)V",                                 reinterpret_cast<void *>(OnTouch)},
      {"resize", "(II)V",                                 reinterpret_cast<void *>(Resize)},
      {"step",   "()V",                                   reinterpret_cast<void *>(Step)},
  };
  int rc = env->RegisterNatives(c, methods, sizeof(ArraySizeHelper(methods)));
  if (rc != JNI_OK) return rc;

  return JNI_VERSION_1_6;
}
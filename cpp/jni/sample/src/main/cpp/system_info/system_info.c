#include <jni.h>
#include <stdio.h>
#include <sys/sysinfo.h>

#include "jni_SystemInfo.h"

JNIEXPORT jstring JNICALL Java_jni_SystemInfo_getMemoryInfo(JNIEnv* env,
                                                            jclass c) {
  char memoryInfo[256];

  struct sysinfo info;
  if (sysinfo(&info) == 0) {
    snprintf(memoryInfo, sizeof(memoryInfo),
             "Total RAM: %ld MB\nFree RAM: %ld MB\n",
             info.totalram / (1024 * 1024), info.freeram / (1024 * 1024));
  } else {
    snprintf(memoryInfo, sizeof(memoryInfo), "Failed to retrieve memory info.");
  }
  return (*env)->NewStringUTF(env, memoryInfo);
}

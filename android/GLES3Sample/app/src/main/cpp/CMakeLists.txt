# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("gles3jni")

include(FetchContent)

FetchContent_Declare(
    assimp
    GIT_REPOSITORY https://github.com/assimp/assimp.git
    GIT_TAG        v6.0.2
)

# Before making it available, set Assimp options as needed
# These are typical options found in Assimp's CMakeLists (check upstream)
set(BUILD_SHARED_LIBS           OFF  CACHE BOOL "Build Assimp as shared library" FORCE)
set(ASSIMP_BUILD_TESTS          OFF  CACHE BOOL "Disable building tests" FORCE)
set(ASSIMP_BUILD_SAMPLES        OFF  CACHE BOOL "Disable building sample apps" FORCE)
set(ASSIMP_BUILD_ASSIMP_TOOLS   OFF  CACHE BOOL "" FORCE)
set(ASSIMP_INSTALL              OFF  CACHE BOOL "Disable install target" FORCE)
set(ASSIMP_INJECT_DEBUG_POSTFIX OFF  CACHE BOOL "Disable debug postfix injection" FORCE)
# You may disable importers / exporters you don't need to reduce compile time
# e.g. set(ASSIMP_BUILD_OBJ_IMPORTER OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(assimp)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm
    GIT_TAG        1.0.1
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(glm)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.
add_library(${CMAKE_PROJECT_NAME} SHARED
        gles3jni.cc
        renderer.cc
        renderer_es3.cc
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${glm_SOURCE_DIR})

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log
        EGL
        GLESv3
        assimp
)
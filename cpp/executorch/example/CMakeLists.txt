cmake_minimum_required(VERSION 3.16)
project(executorch-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(EXECUTORCH_BUILD_EXTENSION_DATA_LOADER ON CACHE BOOL "Enable executorch data loader" FORCE)
set(EXECUTORCH_BUILD_EXTENSION_MODULE ON CACHE BOOL "Enable executorch module" FORCE)
set(EXECUTORCH_BUILD_EXTENSION_TENSOR ON CACHE BOOL "Enable executorch tensor" FORCE)
set(EXECUTORCH_BUILD_EXTENSION_FLAT_TENSOR ON CACHE BOOL "Enable executorch flat tensor" FORCE)
set(EXECUTORCH_BUILD_EXTENSION_NAMED_DATA_MAP ON CACHE BOOL "Enable executorch named data map" FORCE)
set(EXECUTORCH_BUILD_KERNELS_OPTIMIZED ON CACHE BOOL "Enable executorch kernel optimized" FORCE)
set(EXECUTORCH_BUILD_XNNPACK ON CACHE BOOL "Enable executorch xnnpack" FORCE)

FetchContent_Declare(
  executorch
  GIT_REPOSITORY https://github.com/pytorch/executorch.git
  GIT_TAG        v1.0.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
  SOURCE_DIR     ${CMAKE_BINARY_DIR}/executorch
  BINARY_DIR     ${CMAKE_BINARY_DIR}/executorch
)

FetchContent_MakeAvailable(executorch)

# opencv
set(BUILD_EXAMPLES OFF CACHE BOOL "Disable OpenCV examples" FORCE)
set(BUILD_TESTS OFF CACHE BOOL "Disable OpenCV tests" FORCE)
set(BUILD_DOCS OFF CACHE BOOL "Disable OpenCV documentation" FORCE)

# Disable some non-essential OpenCV modules (only enable the ones you need)
set(BUILD_opencv_apps OFF CACHE BOOL "Disable opencv apps" FORCE)
set(BUILD_opencv_calib3d OFF CACHE BOOL "Disable calib3d module" FORCE)
set(BUILD_opencv_features2d OFF CACHE BOOL "Disable features2d module" FORCE)
set(BUILD_opencv_video OFF CACHE BOOL "Disable video module" FORCE)
set(BUILD_opencv_videoio OFF CACHE BOOL "Disable videoio module" FORCE)
set(BUILD_opencv_dnn OFF CACHE BOOL "Disable dnn module" FORCE)
set(BUILD_opencv_ml OFF CACHE BOOL "Disable ml module" FORCE)
set(BUILD_opencv_java OFF CACHE BOOL "Disable java" FORCE)
set(BUILD_opencv_flann OFF CACHE BOOL "Disable flann module" FORCE)
set(BUILD_opencv_photo OFF CACHE BOOL "Disable photo module" FORCE)
set(BUILD_opencv_gapi OFF CACHE BOOL "Disable gapi module" FORCE)
set(BUILD_opencv_objdetect OFF CACHE BOOL "Disable objdetect module" FORCE)
set(BUILD_opencv_stiching OFF CACHE BOOL "Disable stiching" FORCE)
set(BUILD_DOCS OFF CACHE BOOL "Disable opencv docs" FORCE)
set(BUILD_TESTS OFF CACHE BOOL "Disable opencv test" FORCE)

# Enable only the required modules, for example:
set(BUILD_opencv_core ON CACHE BOOL "Enable core module" FORCE)
set(BUILD_opencv_imgproc ON CACHE BOOL "Enable imgproc module" FORCE)
set(BUILD_opencv_highgui ON CACHE BOOL "Enable highgui module" FORCE)

FetchContent_Declare(
  opencv
  GIT_REPOSITORY https://github.com/opencv/opencv.git
  GIT_TAG        4.10.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(opencv)

find_package(Threads REQUIRED)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${CMAKE_BINARY_DIR}
  ${opencv_SOURCE_DIR}/modules/imgproc/include
  ${opencv_SOURCE_DIR}/modules/imgcodecs/include
  ${opencv_SOURCE_DIR}/modules/core/include
  ${opencv_SOURCE_DIR}/modules/highgui/include
  ${opencv_SOURCE_DIR}/include
)
target_link_libraries(example PRIVATE
  extension_module_static
  extension_tensor
  executorch
  xnnpack_backend
  opencv_core
  opencv_imgcodecs
  opencv_imgproc
  Threads::Threads
)

cmake_minimum_required(VERSION 3.14)
project(opencv-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

# Disable building unnecessary OpenCV modules and features
set(BUILD_EXAMPLES OFF CACHE BOOL "Disable OpenCV examples" FORCE)
set(BUILD_TESTS OFF CACHE BOOL "Disable OpenCV tests" FORCE)
set(BUILD_DOCS OFF CACHE BOOL "Disable OpenCV documentation" FORCE)

# Disable some non-essential OpenCV modules (only enable the ones you need)
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

# Enable only the required modules, for example:
set(BUILD_opencv_core ON CACHE BOOL "Enable core module" FORCE)
set(BUILD_opencv_imgproc ON CACHE BOOL "Enable imgproc module" FORCE)
set(BUILD_opencv_highgui ON CACHE BOOL "Enable highgui module" FORCE)

# opencv
FetchContent_Declare(
  opencv
  GIT_REPOSITORY https://github.com/opencv/opencv.git
  GIT_TAG        4.10.0
  GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(opencv)

add_executable(sample sample.cc)
target_include_directories(sample PRIVATE ${opencv_SOURCE_DIR}/modules/imgproc/include)
target_include_directories(sample PRIVATE ${opencv_SOURCE_DIR}/modules/imgcodecs/include)
target_include_directories(sample PRIVATE ${opencv_SOURCE_DIR}/modules/core/include)
target_include_directories(sample PRIVATE ${opencv_SOURCE_DIR}/modules/highgui/include)
target_include_directories(sample PRIVATE ${opencv_SOURCE_DIR}/include)
target_include_directories(sample PRIVATE ${CMAKE_BINARY_DIR})
target_link_libraries(sample PRIVATE opencv_core opencv_imgproc opencv_imgcodecs)

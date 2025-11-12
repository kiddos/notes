cmake_minimum_required(VERSION 3.16)
project(onnx-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_CURL_EXE OFF CACHE BOOL "Disable curl exe" FORCE)
set(CURL_DISABLE_INSTALL ON CACHE BOOL "Disable curl install" FORCE)
set(BUILD_LIBCURL_DOCS OFF CACHE BOOL "Disable libcurl doc" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Disable libcurl shared libs" FORCE)
set(BUILD_STATIC_LIBS ON CACHE BOOL "Build libcurl static lib" FORCE)
FetchContent_Declare(
  curl
  GIT_REPOSITORY https://github.com/curl/curl.git
  GIT_TAG        curl-8_11_0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(curl)

FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11
  GIT_TAG        v2.4.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(CLI11)

FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG        master
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(stb)

FetchContent_Declare(
  onnx
  URL https://github.com/microsoft/onnxruntime/releases/download/v1.20.1/onnxruntime-linux-x64-1.20.1.tgz
)
FetchContent_MakeAvailable(onnx)


add_executable(example example.cc)
target_include_directories(example PRIVATE 
  ${onnx_SOURCE_DIR}/include
  ${CLI11_SOURCE_DIR}/include
  ${stb_SOURCE_DIR}
)
target_compile_definitions(example PRIVATE
  STB_IMAGE_IMPLEMENTATION
  STB_IMAGE_RESIZE2_IMPLEMENTATION
  STB_IMAGE_WRITE_IMPLEMENTATION
)
target_link_directories(example PRIVATE ${onnx_SOURCE_DIR}/lib)
target_link_libraries(example PRIVATE
  onnxruntime
  libcurl
  CLI11
)

cmake_minimum_required(VERSION 3.14)
project(onnx-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

# Fetch ONNX
FetchContent_Declare(
  onnx
  URL https://github.com/microsoft/onnxruntime/releases/download/v1.20.1/onnxruntime-linux-x64-1.20.1.tgz
)
FetchContent_MakeAvailable(onnx)
include_directories(${onnx_SOURCE_DIR}/include)
link_directories(${onnx_SOURCE_DIR}/lib)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE onnxruntime)

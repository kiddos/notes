cmake_minimum_required(VERSION 3.14)
project(llama-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

set(GGML_CUDA ON)
FetchContent_Declare(
  llamacpp
  GIT_REPOSITORY https://github.com/ggerganov/llama.cpp
  GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(llamacpp)

include_directories(${llamacpp-SOURCE_DIR}/include)

add_executable(sample sample.cc)
target_link_libraries(sample llama)

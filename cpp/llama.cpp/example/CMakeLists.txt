cmake_minimum_required(VERSION 3.16)
project(llamacpp-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(GGML_CUDA OFF CACHE BOOL "Disable Cuda" FORCE)
FetchContent_Declare(
  llamacpp
  GIT_REPOSITORY https://github.com/ggerganov/llama.cpp
  GIT_TAG        master
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(llamacpp)

include_directories()

add_executable(example example.cc)
target_include_directories(example PRIVATE ${llamacpp-SOURCE_DIR}/include)
target_link_libraries(example PRIVATE llama)

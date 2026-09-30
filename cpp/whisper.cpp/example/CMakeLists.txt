cmake_minimum_required(VERSION 3.16)
project(whispercpp-example C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)
include(ExternalProject)

FetchContent_Declare(
  whispercpp
  GIT_REPOSITORY https://github.com/ggml-org/whisper.cpp
  GIT_TAG        v1.9.4
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(whispercpp)

add_executable(example example.cc "${whispercpp_SOURCE_DIR}/examples/common-whisper.cpp")
target_include_directories(example PRIVATE "${whispercpp_SOURCE_DIR}/examples")
target_compile_options(example INTERFACE -Wall -Wextra)
target_link_libraries(example
  PRIVATE
  whisper
)

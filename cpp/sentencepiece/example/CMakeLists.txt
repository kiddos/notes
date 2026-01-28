cmake_minimum_required(VERSION 3.16)
project(sentencepiece-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  sentencepiece
  GIT_REPOSITORY https://github.com/google/sentencepiece
  GIT_TAG        v0.2.1
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(sentencepiece)

include_directories(${sentencepiece_SOURCE_DIR}/src)

add_executable(example example.cc)
target_compile_options(example INTERFACE -Wall -Wextra)
target_link_libraries(example PRIVATE sentencepiece)

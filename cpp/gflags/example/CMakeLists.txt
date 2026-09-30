cmake_minimum_required(VERSION 3.16)
project(gflags-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)


FetchContent_Declare(
  gflags
  GIT_REPOSITORY https://github.com/gflags/gflags
  GIT_TAG        v2.3.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(gflags)

add_executable(example example.cc)
target_compile_options(example INTERFACE -Wall -Wextra)
target_link_libraries(example PRIVATE gflags)

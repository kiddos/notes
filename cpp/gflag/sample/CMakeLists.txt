cmake_minimum_required(VERSION 3.14)
project(gflag-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  gflags
  GIT_REPOSITORY https://github.com/gflags/gflags.git
  GIT_TAG        v2.2.2
  GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(gflags)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE gflags)

cmake_minimum_required(VERSION 3.16)
project(raylib-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.5
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(example example.cc)
target_link_libraries(example raylib)

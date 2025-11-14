cmake_minimum_required(VERSION 3.16)
project(libpng-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(PNG_EXECUTABLES OFF CACHE BOOL "Disable png executables" FORCE)
set(PNG_TESTS OFF CACHE BOOL "Disable png tests" FORCE)
set(PNG_TOOLS OFF CACHE BOOL "Disable png tools" FORCE)
FetchContent_Declare(
  libpng
  GIT_REPOSITORY https://github.com/pnggroup/libpng.git
  GIT_TAG        v1.6.50
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(libpng)

add_executable(example example.cc)
target_link_libraries(example PRIVATE png_static)

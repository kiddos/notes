cmake_minimum_required(VERSION 3.16)
project(libpng-sample C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(PNG_EXECUTABLES OFF)
set(PNG_TESTS OFF)
set(PNG_TOOLS OFF)
FetchContent_Declare(
  libpng
  GIT_REPOSITORY https://github.com/pnggroup/libpng.git
  GIT_TAG        v1.6.50
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(libpng)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE png_static)

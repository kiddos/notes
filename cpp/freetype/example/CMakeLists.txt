cmake_minimum_required(VERSION 3.16)
project(freetype-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

# set( ON CACHE BOOL "" FORCE)
FetchContent_Declare(
  freetype
  GIT_REPOSITORY https://github.com/freetype/freetype.git
  GIT_TAG        VER-2-14-1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(freetype)

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

FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11
  GIT_TAG        v2.4.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(CLI11)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${freetype_SOURCE_DIR}/include
  ${CLI11_SOURCE_DIR}/include
)
target_link_libraries(example freetype png_static)

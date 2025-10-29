cmake_minimum_required(VERSION 3.16)
project(zlib-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(ZLIB_BUILD_TESTING OFF CACHE BOOL "Disable zlib testing" FORCE)
set(ZLIB_BUILD_SHARED OFF CACHE BOOL "Disable zlib build shared" FORCE)
set(ZLIB_INSTALL OFF CACHE BOOL "Disable zlib install" FORCE)

FetchContent_Declare(
  zlib
  GIT_REPOSITORY https://github.com/madler/zlib.git
  GIT_TAG        v1.3.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(zlib)

add_executable(zlib-example example.cc)
target_include_directories(zlib-example PRIVATE ${zlib_SOURCE_DIR})
target_link_libraries(zlib-example PRIVATE zlib)

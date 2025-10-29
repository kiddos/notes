cmake_minimum_required(VERSION 3.16)
project(zstd-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(ZSTD_BUILD_STATIC ON CACHE BOOL "Enable zstd static build" FORCE)
set(ZSTD_BUILD_SHARED OFF CACHE BOOL "Disable zstd shared build" FORCE)
set(ZSTD_BUILD_PROGRAMS OFF CACHE BOOL "Disable zstd build programs" FORCE)
set(ZSTD_BUILD_CONTRIB OFF CACHE BOOL "Disable zstd build contrib utilities" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "Disable zstd test build" FORCE)

FetchContent_Declare(
  zstd
  URL "https://github.com/facebook/zstd/releases/download/v1.5.7/zstd-1.5.7.tar.gz"
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  SOURCE_SUBDIR build/cmake
)

FetchContent_MakeAvailable(zstd)

add_executable(example example.cc)
target_link_libraries(example PRIVATE libzstd_static)
target_include_directories(example PRIVATE ${zstd_SOURCE_DIR})

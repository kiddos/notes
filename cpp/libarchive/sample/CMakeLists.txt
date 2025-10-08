cmake_minimum_required(VERSION 3.16)
project(libarchive-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  libarchive
  GIT_REPOSITORY https://github.com/libarchive/libarchive
  GIT_TAG        v3.8.1
  GIT_SHALLOW    TRUE
)

set(ENABLE_TEST OFF CACHE BOOL "Disable unit and regression tests")
set(ENABLE_INSTALL OFF CACHE BOOL "Disable installing of libraries")
FetchContent_MakeAvailable(libarchive)

add_executable(sample sample.cc)
target_include_directories(sample PRIVATE ${libarchive_SOURCE_DIR}/libarchive)
target_link_libraries(sample PRIVATE archive)

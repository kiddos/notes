cmake_minimum_required(VERSION 3.14)
project(zlib-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  zlib
  GIT_REPOSITORY https://github.com/madler/zlib.git
  GIT_TAG        v1.3.1
  GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(zlib)

add_executable(sample sample.cc)

target_include_directories(sample PRIVATE ${zlib_SOURCE_DIR})

target_link_libraries(sample PRIVATE zlib)

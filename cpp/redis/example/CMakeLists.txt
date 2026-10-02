cmake_minimum_required(VERSION 3.14)
project(hiredis-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  hiredis
  GIT_REPOSITORY https://github.com/redis/hiredis.git
  GIT_TAG        v1.3.0  # Use a stable release tag for hiredis
  SOURCE_DIR     ${CMAKE_BINARY_DIR}/_deps/hiredis-src
)

FetchContent_MakeAvailable(hiredis)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE hiredis)

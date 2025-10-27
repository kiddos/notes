cmake_minimum_required(VERSION 3.16)
project(libuv-example C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
    libuv
    GIT_REPOSITORY https://github.com/libuv/libuv.git
    GIT_TAG        v1.51.0
    GIT_SHALLOW    TRUE
    GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(libuv)

find_package(OpenSSL REQUIRED)

add_executable(example example.cc)
target_link_libraries(example PRIVATE uv)

add_executable(http_example http_example.cc)
target_link_libraries(http_example PRIVATE
  uv
  OpenSSL::SSL
  OpenSSL::Crypto)

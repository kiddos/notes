cmake_minimum_required(VERSION 3.14)
project(libuv-sample C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
    libuv
    GIT_REPOSITORY https://github.com/libuv/libuv.git
    GIT_TAG        v1.51.0
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(libuv)

find_package(OpenSSL REQUIRED)

add_executable(sample sample.cc)

target_link_libraries(sample PRIVATE uv)

add_executable(http_sample http_sample.cc)

target_link_libraries(http_sample PRIVATE uv OpenSSL::SSL OpenSSL::Crypto)

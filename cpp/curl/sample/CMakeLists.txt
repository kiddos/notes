cmake_minimum_required(VERSION 3.14)
project(curl-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
    curl
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG        curl-8_11_0
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(curl)

add_executable(sample sample.cc request.cc)
target_link_libraries(sample PRIVATE libcurl)

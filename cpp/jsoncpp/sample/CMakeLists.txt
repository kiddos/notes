cmake_minimum_required(VERSION 3.14)
project(jsoncpp-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  jsoncpp
  GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG 1.9.6
  GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(jsoncpp)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE jsoncpp_lib)

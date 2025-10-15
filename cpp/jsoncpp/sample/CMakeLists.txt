cmake_minimum_required(VERSION 3.16)
project(jsoncpp-sample CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(JSONCPP_WITH_TESTS OFF)
set(JSONCPP_WITH_POST_BUILD_UNITTEST OFF)
set(JSONCPP_WITH_PKGCONFIG_SUPPORT OFF)
set(JSONCPP_WITH_EXAMPLE OFF)
set(BUILD_OBJECT_LIBS OFF)
FetchContent_Declare(
  jsoncpp
  GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG 1.9.6
  GIT_SHALLOW TRUE
  GIT_PROGRESS
)

FetchContent_MakeAvailable(jsoncpp)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE jsoncpp_lib)

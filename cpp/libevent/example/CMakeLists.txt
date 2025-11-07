cmake_minimum_required(VERSION 3.16)
project(libevent-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(EVENT__DISABLE_DEBUG_MODE ON CACHE BOOL "Disable libevent debug mode" FORCE)
set(EVENT__DISABLE_OPENSSL ON CACHE BOOL "Disable libevent openssl" FORCE)
set(EVENT__DISABLE_REGRESSION_TEST ON CACHE BOOL "Disable libevent regression test" FORCE)
set(EVENT__DISABLE_SAMPLES ON CACHE BOOL "Disable libevent samples" FORCE)
set(EVENT__DISABLE_BENCHMARK ON CACHE BOOL "Disable libevent benchmark" FORCE)
set(EVENT__DISABLE_TESTS ON CACHE BOOL "Disable libevent tests" FORCE)
set(EVENT__DISABLE_REGRESS ON CACHE BOOL "Disable libevent regress" FORCE)
set(EVENT__DISABLE_DOXYGEN ON CACHE BOOL "Disable libevent docs" FORCE)
FetchContent_Declare(
  libevent
  GIT_REPOSITORY https://github.com/libevent/libevent.git
  GIT_TAG        release-2.1.12-stable
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(libevent)

set(JSONCPP_WITH_TESTS OFF CACHE BOOL "Disable jsoncpp tests" FORCE)
set(JSONCPP_WITH_POST_BUILD_UNITTEST OFF CACHE BOOL "Disable jsoncpp unit tests" FORCE)
set(JSONCPP_WITH_PKGCONFIG_SUPPORT OFF CACHE BOOL "Disable jsoncpp pkgconfig" FORCE)
set(JSONCPP_WITH_EXAMPLE OFF CACHE BOOL "Disable jsoncpp examples" FORCE)
set(BUILD_OBJECT_LIBS OFF CACHE BOOL "Disable build object libs" FORCE)
FetchContent_Declare(
  jsoncpp
  GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG        1.9.6
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(jsoncpp)

add_executable(example example.cc)
target_include_directories(example PRIVATE ${libevent_SOURCE_DIR}/include)
target_link_libraries(example PRIVATE
  event_core
  event_extra
  jsoncpp_lib
)

cmake_minimum_required(VERSION 3.16)
project(libevent-sample LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

set(EVENT__DISABLE_DEBUG_MODE ON)
set(EVENT__DISABLE_OPENSSL ON)
set(EVENT__DISABLE_REGRESSION_TEST ON)
set(EVENT__DISABLE_SAMPLES ON)
set(EVENT__DISABLE_BENCHMARK ON)
set(EVENT__DISABLE_TESTS ON)
set(EVENT__DISABLE_REGRESS ON)
set(EVENT__DISABLE_DOXYGEN ON)
FetchContent_Declare(
  libevent
  GIT_REPOSITORY https://github.com/libevent/libevent.git
  GIT_TAG        release-2.1.12-stable
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(libevent)

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

target_link_libraries(sample PRIVATE
  event_core
  event_extra
  jsoncpp_lib)
target_include_directories(sample PRIVATE
  ${libevent_SOURCE_DIR}/include)

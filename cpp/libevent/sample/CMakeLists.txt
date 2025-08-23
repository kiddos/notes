cmake_minimum_required(VERSION 3.16)
project(libevent-sample LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  libevent
  GIT_REPOSITORY https://github.com/libevent/libevent.git
  GIT_TAG        release-2.1.12-stable
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
  CMAKE_ARGS
      -DBUILD_SHARED_LIBS=OFF
      -DEVENT__DISABLE_DEBUG_MODE=ON
      -DEVENT__DISABLE_OPENSSL=ON # Set to OFF if you need OpenSSL support
      -DEVENT__DISABLE_REGRESSION_TEST=ON
      -DEVENT__DISABLE_SAMPLES=ON
      -DEVENT__DISABLE_BENCHMARK=ON
      -DEVENT__DISABLE_DOXYGEN=ON
)

FetchContent_MakeAvailable(libevent)

add_executable(sample sample.cc)

target_link_libraries(sample PRIVATE event_core event_extra)
target_include_directories(sample PRIVATE ${libevent_SOURCE_DIR}/include)

cmake_minimum_required(VERSION 3.16)
project(hidapi-sample C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  hidapi
  GIT_REPOSITORY https://github.com/libusb/hidapi.git
  GIT_TAG        hidapi-0.15.0
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(hidapi)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE
  hidapi::libusb
)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  pico_sdk
  URL https://github.com/raspberrypi/pico-sdk/releases/download/2.2.0/pico-sdk-2.2.0.tar.gz
)
FetchContent_GetProperties(pico_sdk)
if (NOT pico_sdk_POPULATED)
  FetchContent_Populate(pico_sdk)
  set(PICO_SDK_PATH ${pico_sdk_SOURCE_DIR} CACHE PATH "Path to the Pico SDK" FORCE)
endif()

include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(blink C CXX ASM)

pico_sdk_init()

add_executable(blink
  main.c
)
pico_enable_stdio_usb(blink 1)

# pull in common dependencies
target_link_libraries(blink
  pico_stdlib
)

pico_add_extra_outputs(blink)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT DEFINED ENV{PICO_SDK_PATH})
  message(FATAL_ERROR "Error: PICO_SDK_PATH is not set. Please set it before running CMake.")
endif()

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
# include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
project(blink_sample C CXX ASM)

pico_sdk_init()

if (NOT DEFINED PICO_CYW43_SUPPORTED)
  message(FATAL_ERROR "set by PICO_BOARD=pico_w")
endif()

if (NOT TARGET pico_cyw43_arch)
  message(FATAL_ERROR "Skipping Pico W examples as support is not available")
endif()

add_executable(blink
  main.cc
)
pico_enable_stdio_usb(blink 1)
# pico_enable_stdio_uart(blink 0)

# pull in common dependencies
target_link_libraries(blink
  pico_stdlib
  pico_cyw43_arch_none
  )

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT DEFINED ENV{PICO_SDK_PATH})
  message(FATAL_ERROR "Error: PICO_SDK_PATH is not set. Please set it before running CMake.")
endif()

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include(FetchContent)
project(lcd_sample C CXX ASM)

pico_sdk_init()

FetchContent_Declare(
  waveshare
  GIT_REPOSITORY https://github.com/kiddos/Pico_code.git
  GIT_TAG        main
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(waveshare)

message(${waveshare_SOURCE_DIR})

add_executable(lcd_sample
  main.c
  ${waveshare_SOURCE_DIR}/c/lib/Config/DEV_Config.c
  ${waveshare_SOURCE_DIR}/c/lib/GUI/GUI_Paint.c
  ${waveshare_SOURCE_DIR}/c/lib/LCD/LCD_1in8.c
)
pico_enable_stdio_usb(lcd_sample 1)

include_directories(${waveshare_SOURCE_DIR}/c/lib/Config)
include_directories(${waveshare_SOURCE_DIR}/c/lib/LCD)
include_directories(${waveshare_SOURCE_DIR}/c/lib/GUI)

# pull in common dependencies
target_link_libraries(lcd_sample
  pico_stdlib
  hardware_spi
  hardware_i2c
  hardware_pwm
)

pico_add_extra_outputs(lcd_sample)

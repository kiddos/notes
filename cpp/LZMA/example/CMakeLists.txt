cmake_minimum_required(VERSION 3.16)
project(LZMA-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

# set( ON CACHE BOOL "" FORCE)
FetchContent_Declare(
  lzma
  URL https://www.7-zip.org/a/lzma2501.7z
)
FetchContent_MakeAvailable(lzma)

include_directories(
  ${lzma_SOURCE_DIR}/C
  ${lzma_SOURCE_DIR}/CPP
)
file(GLOB LZMA_C_SOURCE "${lzma_SOURCE_DIR}/C/*.c")

add_library(lzma ${LZMA_C_SOURCE})

add_executable(example example.cc)
target_link_libraries(example PRIVATE lzma)

cmake_minimum_required(VERSION 3.14)
project(zstd-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

set(ZSTD_BUILD_STATIC ON)
set(ZSTD_BUILD_SHARED OFF)

FetchContent_Declare(
  zstd
  URL "https://github.com/facebook/zstd/releases/download/v1.5.5/zstd-1.5.5.tar.gz"
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  SOURCE_SUBDIR build/cmake
)

FetchContent_MakeAvailable(zstd)

add_executable(${PROJECT_NAME} sample.cc)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  libzstd_static
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${zstd_SOURCE_DIR}/lib
)

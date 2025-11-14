cmake_minimum_required(VERSION 3.16)
project(libzip-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  libzip
  GIT_REPOSITORY https://github.com/nih-at/libzip.git
  GIT_TAG        v1.11.4
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

set(LIBZIP_WITH_BZIP2 ON CACHE BOOL "" FORCE)
set(LIBZIP_WITH_LZMA ON CACHE BOOL "" FORCE)
set(LIBZIP_WITH_OPENSSL OFF CACHE BOOL "" FORCE)
set(LIBZIP_WITH_ZSTD ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(libzip)

add_executable(example example.cc)
target_link_libraries(example PRIVATE libzip::zip)
target_include_directories(example PRIVATE
  ${libzip_SOURCE_DIR}/lib
  ${libzip_BINARY_DIR}
)

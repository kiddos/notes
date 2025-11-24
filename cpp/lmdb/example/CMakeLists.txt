cmake_minimum_required(VERSION 3.16)
project(lmdb-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  lmdb
  GIT_REPOSITORY https://github.com/LMDB/lmdb.git
  GIT_TAG        LMDB_0.9.31
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(lmdb)

find_package(Threads REQUIRED)

set(LMDB_DIR "${lmdb_SOURCE_DIR}/libraries/liblmdb")

add_library(lmdb
  ${LMDB_DIR}/mdb.c
  ${LMDB_DIR}/midl.c
)
target_include_directories(lmdb PRIVATE ${LMDB_DIR})

add_executable(example example.c)
target_include_directories(example PRIVATE ${LMDB_DIR})
target_link_libraries(example PRIVATE lmdb Threads::Threads)

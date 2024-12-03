cmake_minimum_required(VERSION 3.14)
project(sqlite-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

find_package(Threads REQUIRED)

FetchContent_Declare(
    sqlite
    URL       "https://www.sqlite.org/2024/sqlite-amalgamation-3470000.zip"
    URL_HASH  SHA256=2842fddbb1cc33f66c7da998a57535f14a6bfee159676a07bb4bf3e59375d93e
)
FetchContent_MakeAvailable(sqlite)

include_directories(${sqlite_SOURCE_DIR})

add_library(sqlite3 STATIC ${sqlite_SOURCE_DIR}/sqlite3.c)
target_link_libraries(sqlite3 Threads::Threads dl)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE sqlite3)

cmake_minimum_required(VERSION 3.10)
project(SQLiteSample)

find_package(Threads REQUIRED)
include(ExternalProject)

set(SQLITE_DOWNLOAD_URL "https://www.sqlite.org/2024/sqlite-amalgamation-3470000.zip")

set(SQLITE_TARGET_DIR "${CMAKE_BINARY_DIR}/sqlite.zip")
if(NOT EXISTS ${SQLITE_TARGET_DIR})
  file(DOWNLOAD ${SQLITE_DOWNLOAD_URL} ${SQLITE_TARGET_DIR} SHOW_PROGRESS)
  execute_process(COMMAND unzip ${SQLITE_TARGET_DIR}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
endif()

# Define SQLite as a library target, linking the compiled sqlite3 object file
include_directories("${CMAKE_BINARY_DIR}/sqlite-amalgamation-3470000/")
add_library(sqlite3 STATIC ${CMAKE_BINARY_DIR}/sqlite-amalgamation-3470000/sqlite3.c)
target_link_libraries(sqlite3 Threads::Threads)
# Add include directory for SQLite headers
add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE sqlite3 dl)

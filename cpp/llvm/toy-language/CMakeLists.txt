cmake_minimum_required(VERSION 3.14)
project(llvm-toy-language)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(LLVM 20 REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM Include Dir: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM Libraries: ${LLVM_LIBRARY_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(toy-language main.cc)

target_link_libraries(toy-language PRIVATE LLVM)

file(GLOB TEST_FILES "${CMAKE_SOURCE_DIR}/*.txt")
foreach(TEST_FILE ${TEST_FILES})
  configure_file(${TEST_FILE} ${CMAKE_BINARY_DIR} COPYONLY)
endforeach()

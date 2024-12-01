cmake_minimum_required(VERSION 3.14)
project(sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    expat
    GIT_REPOSITORY https://github.com/libexpat/libexpat/
    GIT_TAG R_2_6_4
    SOURCE_SUBDIR expat/
)

FetchContent_MakeAvailable(expat)

file(COPY ${CMAKE_SOURCE_DIR}/sample1.xml DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY ${CMAKE_SOURCE_DIR}/sample2.xml DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY ${CMAKE_SOURCE_DIR}/sample3.xml DESTINATION ${CMAKE_BINARY_DIR}/)

add_executable(sample sample.cc xml_parser.cc)
target_link_libraries(sample PUBLIC expat)

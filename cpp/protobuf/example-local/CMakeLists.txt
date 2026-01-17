cmake_minimum_required(VERSION 3.16)
project(protobuf-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

find_package(protobuf REQUIRED)

add_executable(example example.cc)
set(PROTO_FILE ${CMAKE_CURRENT_SOURCE_DIR}/example.proto)
protobuf_generate(TARGET example PROTOS ${PROTO_FILE})
target_include_directories(example PRIVATE ${CMAKE_BINARY_DIR})
target_link_libraries(example PRIVATE protobuf::libprotobuf)

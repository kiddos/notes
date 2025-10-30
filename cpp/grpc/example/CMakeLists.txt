cmake_minimum_required(VERSION 3.16)
project(grpc-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_TESTS OFF CACHE BOOL "Disable build tests" FORCE)
set(protobuf_INSTALL OFF CACHE BOOL "Disable protobuf install" FORCE)
set(utf8_range_ENABLE_INSTALL OFF CACHE BOOL "Disable utf8_range install" FORCE)

FetchContent_Declare(
  grpc
  GIT_REPOSITORY https://github.com/grpc/grpc.git
  GIT_TAG        v1.75.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(grpc)

set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

set(PROTO_FILE ${CMAKE_CURRENT_SOURCE_DIR}/example.proto)
get_filename_component(PROTO_PATH "${PROTO_FILE}" PATH)
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

set(PROTO_SOURCE
  ${CMAKE_CURRENT_BINARY_DIR}/example.pb.cc
  ${CMAKE_CURRENT_BINARY_DIR}/example.grpc.pb.cc
)

set(PROTO_HEADER
  ${CMAKE_CURRENT_BINARY_DIR}/example.pb.h
  ${CMAKE_CURRENT_BINARY_DIR}/example.grpc.pb.h
)

add_custom_command(
  OUTPUT ${PROTO_SOURCE} ${PROTO_HEADER}
  COMMAND ${_PROTOBUF_PROTOC}
  ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
    --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
    -I "${PROTO_PATH}"
    --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
    "${PROTO_FILE}"
  DEPENDS "${PROTO_FILE}")

add_library(grpc_example_proto STATIC
  ${PROTO_SOURCE}
  ${PROTO_HEADER})
target_link_libraries(grpc_example_proto
  grpc++_reflection
  grpc++
  protobuf::libprotobuf)

add_executable(example-server server.cc)
target_link_libraries(example-server PRIVATE
  grpc_example_proto
  grpc++_reflection
  grpc++
  protobuf::libprotobuf)

add_executable(example-client client.cc)
target_link_libraries(example-client PRIVATE
  grpc_example_proto
  grpc++_reflection
  grpc++
  protobuf::libprotobuf)

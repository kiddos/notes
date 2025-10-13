cmake_minimum_required(VERSION 3.16)
project(grpc-sample C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_TESTS OFF)

FetchContent_Declare(
  grpc
  GIT_REPOSITORY https://github.com/grpc/grpc.git
  GIT_TAG        v1.75.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

set(protobuf_INSTALL OFF)
set(utf8_range_ENABLE_INSTALL OFF)

FetchContent_MakeAvailable(grpc)

set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

set(PROTO_FILE ${CMAKE_CURRENT_SOURCE_DIR}/sample.proto)
get_filename_component(PROTO_PATH "${PROTO_FILE}" PATH)
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

set(PROTO_SOURCE
  ${CMAKE_CURRENT_BINARY_DIR}/sample.pb.cc
  ${CMAKE_CURRENT_BINARY_DIR}/sample.grpc.pb.cc
)

set(PROTO_HEADER
  ${CMAKE_CURRENT_BINARY_DIR}/sample.pb.h
  ${CMAKE_CURRENT_BINARY_DIR}/sample.grpc.pb.h
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

add_library(grpc_sample_proto STATIC
  ${PROTO_SOURCE}
  ${PROTO_HEADER})
target_link_libraries(grpc_sample_proto
  grpc++_reflection
  grpc++
  protobuf::libprotobuf)

add_executable(sample-server server.cc)
target_link_libraries(sample-server PRIVATE
  grpc_sample_proto
  grpc++_reflection
  grpc++
  protobuf::libprotobuf)

add_executable(sample-client client.cc)
target_link_libraries(sample-client PRIVATE
  grpc_sample_proto
  grpc++_reflection
  grpc++
  protobuf::libprotobuf)

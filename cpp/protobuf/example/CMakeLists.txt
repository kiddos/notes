cmake_minimum_required(VERSION 3.16)
project(protobuf-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(protobuf_INSTALL OFF CACHE BOOL "Disable protobuf install" FORCE)
set(protobuf_BUILD_TESTS OFF CACHE BOOL "Disable protobuf tests" FORCE)
set(protobuf_BUILD_EXAMPLES OFF CACHE BOOL "Disable protobuf examples" FORCE)
FetchContent_Declare(
  protobuf
  GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
  GIT_TAG        v31.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(protobuf)

set(PROTO_FILE ${CMAKE_CURRENT_SOURCE_DIR}/example.proto)

# Define the output paths for the generated C++ source and header files
set(PROTO_SRCS ${CMAKE_CURRENT_BINARY_DIR}/example.pb.cc)
set(PROTO_HDRS ${CMAKE_CURRENT_BINARY_DIR}/example.pb.h)

add_custom_command(
  OUTPUT ${PROTO_SRCS} ${PROTO_HDRS}
  # The command to execute is the protoc compiler
  COMMAND $<TARGET_FILE:protobuf::protoc>
  # Arguments to protoc
  ARGS --cpp_out=${CMAKE_CURRENT_BINARY_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} ${PROTO_FILE}
  # This command depends on the protoc executable and the .proto file
  DEPENDS protobuf::protoc ${PROTO_FILE}
  COMMENT "Generating C++ sources from ${PROTO_FILE}"
)

add_custom_target(
  GenerateProtoSources
  DEPENDS ${PROTO_SRCS} ${PROTO_HDRS}
)

add_executable(example example.cc)
add_dependencies(example GenerateProtoSources)
target_sources(example PRIVATE ${PROTO_SRCS})
target_include_directories(example PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(example PRIVATE protobuf::libprotobuf)

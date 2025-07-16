cmake_minimum_required(VERSION 3.14)
project(protobuf-sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  protobuf
  GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
  GIT_TAG        v31.1
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(protobuf)

set(PROTO_FILE ${CMAKE_CURRENT_SOURCE_DIR}/sample.proto)

# Define the output paths for the generated C++ source and header files
set(PROTO_SRCS ${CMAKE_CURRENT_BINARY_DIR}/sample.pb.cc)
set(PROTO_HDRS ${CMAKE_CURRENT_BINARY_DIR}/sample.pb.h)

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

add_executable(sample sample.cc)
add_dependencies(sample GenerateProtoSources)
target_sources(sample PRIVATE ${PROTO_SRCS})
target_include_directories(sample PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(sample PRIVATE protobuf::libprotobuf)

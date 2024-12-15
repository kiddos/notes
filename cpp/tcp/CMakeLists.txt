cmake_minimum_required(VERSION 3.14)
project(tcp-example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(client client_app.cc client.cc)
add_executable(server server_app.cc server.cc)

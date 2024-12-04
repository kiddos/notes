cmake_minimum_required(VERSION 3.14)
project(project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(/opt/IBM/dsdriver-v11.5.4/include)
link_directories(/opt/IBM/dsdriver-v11.5.4/lib)

add_executable(sample sample.cc db2_connection.cc)
target_link_libraries(sample PRIVATE db2)

cmake_minimum_required(VERSION 3.16)
project(db2-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(/opt/IBM/dsdriver-v11.5.4/include)
link_directories(/opt/IBM/dsdriver-v11.5.4/lib)

add_executable(example example.cc db2_connection.cc)
target_link_libraries(example PRIVATE db2)

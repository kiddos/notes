cmake_minimum_required(VERSION 3.14)
project(mongodb-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  mongo-cxx-driver
  GIT_REPOSITORY   https://github.com/mongodb/mongo-cxx-driver.git
  GIT_TAG          r4.0.0
  GIT_SHALLOW      TRUE
)
FetchContent_MakeAvailable(mongo-cxx-driver)

add_executable(sample sample.cc)

target_link_libraries(sample PRIVATE 
  bsoncxx_shared
  mongocxx_shared
)

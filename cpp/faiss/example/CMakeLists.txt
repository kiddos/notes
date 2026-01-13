cmake_minimum_required(VERSION 3.16)
project(faiss-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(FAISS_ENABLE_GPU OFF CACHE BOOL "faiss disable GPU" FORCE)
set(FAISS_ENABLE_MKL OFF CACHE BOOL "faiss disable MKL" FORCE)
set(FAISS_ENABLE_PYTHON OFF CACHE BOOL "faiss disable python" FORCE)
set(FAISS_ENABLE_C_API ON CACHE BOOL "faiss enable c API" FORCE)
set(FAISS_ENABLE_EXTRAS OFF CACHE BOOL "faiss disable extras" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "faiss disable testings" FORCE)

FetchContent_Declare(
  faiss
  GIT_REPOSITORY https://github.com/facebookresearch/faiss.git
  GIT_TAG        v1.13.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(faiss)

add_executable(example example.cc)
target_link_libraries(example PRIVATE faiss)

cmake_minimum_required(VERSION 3.16)
project(jemalloc-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(ExternalProject)

set(EXTERNAL_INSTALL_DIR "${CMAKE_BINARY_DIR}/external")

ExternalProject_Add(
  external_jemalloc
  URL https://github.com/jemalloc/jemalloc/releases/download/5.4.0/jemalloc-5.4.0.tar.bz2
  URL_HASH SHA256=200776fac271093e7c2f21edd6d62657ecd2be578d9328633f2a86bfa6ef4f1d
  CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${EXTERNAL_INSTALL_DIR}
  BUILD_COMMAND     make
  INSTALL_COMMAND   make install
  BUILD_BYPRODUCTS  ${EXTERNAL_INSTALL_DIR}/lib/libjemalloc.a
)

add_library(libjemalloc STATIC IMPORTED)
file(MAKE_DIRECTORY "${EXTERNAL_INSTALL_DIR}/include")
set_target_properties(libjemalloc PROPERTIES
  IMPORTED_LOCATION "${EXTERNAL_INSTALL_DIR}/lib/libjemalloc.a"
  INTERFACE_INCLUDE_DIRECTORIES "${EXTERNAL_INSTALL_DIR}/include"
)

add_executable(example example.cc)
target_compile_options(example INTERFACE -Wall -Wextra)
target_include_directories(example PRIVATE "${EXTERNAL_INSTALL_DIR}/include")
target_link_libraries(example
  PRIVATE
  libjemalloc
)

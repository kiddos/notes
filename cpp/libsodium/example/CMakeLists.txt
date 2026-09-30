cmake_minimum_required(VERSION 3.16)
project(libsodium-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(ExternalProject)

set(EXTERNAL_INSTALL_DIR "${CMAKE_BINARY_DIR}/external")

ExternalProject_Add(
  external_libsodium
  URL https://github.com/jedisct1/libsodium/releases/download/1.0.22-RELEASE/libsodium-1.0.22.tar.gz
  URL_HASH SHA256=adbdd8f16149e81ac6078a03aca6fc03b592b89ef7b5ed83841c086191be3349
  CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${EXTERNAL_INSTALL_DIR}
  BUILD_COMMAND     make
  INSTALL_COMMAND   make install
  BUILD_BYPRODUCTS  ${EXTERNAL_INSTALL_DIR}/lib/libsodium.a
)

add_library(libsodium STATIC IMPORTED)
file(MAKE_DIRECTORY "${EXTERNAL_INSTALL_DIR}/include")
set_target_properties(libsodium PROPERTIES
  IMPORTED_LOCATION "${EXTERNAL_INSTALL_DIR}/lib/libsodium.a"
  INTERFACE_INCLUDE_DIRECTORIES "${EXTERNAL_INSTALL_DIR}/include"
)

add_dependencies(libsodium external_libsodium)

add_executable(example example.cc)
target_include_directories(example PRIVATE "${EXTERNAL_INSTALL_DIR}/include")
target_compile_options(example INTERFACE -Wall -Wextra)
target_link_libraries(example
  PRIVATE
  libsodium
)

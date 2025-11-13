cmake_minimum_required(VERSION 3.14)
project(curl-sample C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)
include(ExternalProject)

FetchContent_Declare(
  openssl
  GIT_REPOSITORY https://github.com/openssl/openssl
  GIT_TAG        openssl-3.5.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(openssl)

set(OPENSSL_BUILD_DIR "${CMAKE_BINARY_DIR}/openssl-build")
set(OPENSSL_INSTALL_PREFIX "${OPENSSL_BUILD_DIR}/install")
ExternalProject_Add(openssl_external_project
  SOURCE_DIR "${openssl_SOURCE_DIR}"
  BINARY_DIR "${OPENSSL_BUILD_DIR}"
  CONFIGURE_COMMAND perl "${openssl_SOURCE_DIR}/Configure" -static -no-docs --prefix=${OPENSSL_INSTALL_PREFIX}
  BUILD_COMMAND $(MAKE) -j8
  INSTALL_COMMAND $(MAKE) install
  BUILD_BYPRODUCTS
      "${OPENSSL_INSTALL_PREFIX}/lib64/libssl.a"
      "${OPENSSL_INSTALL_PREFIX}/lib64/libcrypto.a"
  CLEAN_COMMAND ${CMAKE_COMMAND} -E remove_directory "${OPENSSL_BUILD_DIR}"
)

FetchContent_Declare(
  libcurl
  URL https://curl.se/download/curl-8.15.0.tar.gz
)

FetchContent_GetProperties(libcurl)
if(NOT libcurl_POPULATED)
  FetchContent_Populate(libcurl)
endif()

set(LIBCURL_BUILD_DIR "${CMAKE_BINARY_DIR}/libcurl-build")
set(LIBCURL_INSTALL_PREFIX "${LIBCURL_BUILD_DIR}/install")

ExternalProject_Add(libcurl_external_project
  SOURCE_DIR "${libcurl_SOURCE_DIR}"
  BINARY_DIR "${LIBCURL_BUILD_DIR}"
  CONFIGURE_COMMAND <SOURCE_DIR>/configure
                    --prefix=${LIBCURL_INSTALL_PREFIX}
                    --with-openssl=${OPENSSL_INSTALL_PREFIX}
                    --disable-shared
                    --without-zlib
                    --without-brotli
                    --without-libpsl
  BUILD_COMMAND $(MAKE) -j8
  INSTALL_COMMAND $(MAKE) install
  DEPENDS openssl_external_project
)

set(LIBCURL_INCLUDE_DIR "${LIBCURL_INSTALL_PREFIX}/include")
set(LIBCURL_LIB "${LIBCURL_INSTALL_PREFIX}/lib/libcurl.a")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_INSTALL_PREFIX}/include")
set(OPENSSL_SSL_LIB "${OPENSSL_INSTALL_PREFIX}/lib64/libssl.a")
set(OPENSSL_CRYPTO_LIB "${OPENSSL_INSTALL_PREFIX}/lib64/libcrypto.a")

find_package(Threads REQUIRED)

add_executable(example example.cc)
# target_link_libraries(sample PRIVATE libcurl)
target_include_directories(example PRIVATE
  ${LIBCURL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)
target_link_libraries(example PRIVATE
    ${LIBCURL_LIB}
    ${OPENSSL_SSL_LIB}
    ${OPENSSL_CRYPTO_LIB}
    dl
    Threads::Threads
)
add_dependencies(example openssl_external_project)

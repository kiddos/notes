cmake_minimum_required(VERSION 3.16)
project(icu-example C CXX)

set(CMAKE_CXX_STANDARD 17)
# set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(ExternalProject)

set(ICU_PREFIX ${CMAKE_BINARY_DIR}/external/icu)
set(ICU_INCLUDE_DIR ${ICU_PREFIX}/include)
set(ICU_LIB_DIR ${ICU_PREFIX}/lib)

ExternalProject_Add(icu_setup
  GIT_REPOSITORY      https://github.com/unicode-org/icu.git
  GIT_TAG             release-76-1
  SOURCE_SUBDIR       icu4c/source
  PREFIX              ${ICU_PREFIX}
  UPDATE_COMMAND      ""
  CONFIGURE_COMMAND   <SOURCE_DIR>/icu4c/source/configure 
                      --prefix=${ICU_PREFIX}
                      --enable-static
                      --disable-shared
                      --disable-tests
                      --disable-samples
  BUILD_COMMAND       make
  INSTALL_COMMAND     make install
  CONFIGURE_HANDLED_BY_BUILD ON
)

file(MAKE_DIRECTORY ${ICU_INCLUDE_DIR})

add_library(icu::uc STATIC IMPORTED)
set_target_properties(icu::uc PROPERTIES
  IMPORTED_LOCATION ${ICU_LIB_DIR}/libicuuc.a
  INTERFACE_INCLUDE_DIRECTORIES ${ICU_INCLUDE_DIR}
)

add_library(icu::data STATIC IMPORTED)
set_target_properties(icu::data PROPERTIES
  IMPORTED_LOCATION ${ICU_LIB_DIR}/libicudata.a
  INTERFACE_INCLUDE_DIRECTORIES ${ICU_INCLUDE_DIR}
)

add_library(icu::i18n STATIC IMPORTED)
set_target_properties(icu::i18n PROPERTIES
  IMPORTED_LOCATION ${ICU_LIB_DIR}/libicui18n.a
  INTERFACE_INCLUDE_DIRECTORIES ${ICU_INCLUDE_DIR}
)

add_executable(example example.cc)
target_compile_options(example INTERFACE -Wall -Wextra)
add_dependencies(example icu_setup)
target_link_libraries(example PRIVATE icu::uc icu::i18n icu::data)

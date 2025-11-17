cmake_minimum_required(VERSION 3.16)
project(zbar-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)
include(ExternalProject)

set(ZBAR_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/zbar")
ExternalProject_Add(zbar_external_project
  GIT_REPOSITORY  https://github.com/mchehab/zbar
  GIT_TAG         0.23
  GIT_SHALLOW     TRUE
  GIT_PROGRESS    TRUE
  BUILD_IN_SOURCE TRUE
  CONFIGURE_COMMAND sh -c "test -x ./configure || (autoreconf -vfi && ./configure --without-qt --without-java --with-python=no --disable-doc --disable-pthread --with-gtk=no --prefix=${ZBAR_INSTALL_PREFIX})"
  BUILD_COMMAND $(MAKE) -j8
)

FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG        master
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(stb)

add_executable(example example.cc)
add_dependencies(example zbar_external_project)
target_include_directories(example PRIVATE 
  ${ZBAR_INSTALL_PREFIX}/include
  ${stb_SOURCE_DIR}
)
target_link_directories(example PRIVATE ${ZBAR_INSTALL_PREFIX}/lib)
target_compile_definitions(example PUBLIC
  STB_IMAGE_IMPLEMENTATION
  STB_IMAGE_RESIZE2_IMPLEMENTATION
  STB_IMAGE_WRITE_IMPLEMENTATION
)
target_link_libraries(example PRIVATE zbar)

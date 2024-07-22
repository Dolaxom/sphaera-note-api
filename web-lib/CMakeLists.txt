cmake_minimum_required(VERSION 3.11)

project(Weblib CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Crow REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_library(weblib
  src/router.cc
  src/router.h
  src/server.cc
  src/server.h
  src/request.cc
  src/request.h

  src/types.h
)
target_link_libraries(weblib PRIVATE Crow::Crow Threads::Threads)

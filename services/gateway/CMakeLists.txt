cmake_minimum_required(VERSION 3.11)

project(Gateway CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/../../web-lib/build/")

find_package(Crow REQUIRED)
find_package(Threads REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/../../web-lib weblib_build)

add_executable(gateway src/main.cc src/routes/route.cc src/routes/route.h)
target_link_libraries(gateway PRIVATE weblib Crow::Crow Threads::Threads)

include_directories(gateway PRIVATE ../../web-lib/src)


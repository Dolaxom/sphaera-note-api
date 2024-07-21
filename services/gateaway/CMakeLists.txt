cmake_minimum_required(VERSION 3.11)

project(Gateway CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Crow REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(gateway src/main.cc)
target_link_libraries(gateway PRIVATE Crow::Crow Threads::Threads)

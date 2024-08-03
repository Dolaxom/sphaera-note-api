cmake_minimum_required(VERSION 3.11)

project(Gateway CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/../../web-lib/build/")

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_package(Crow REQUIRED)
find_package(Threads REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/../../web-lib weblib_build)

add_executable(gateway
    src/main.cc
    src/routes/route.cc
    src/routes/route.h

)
target_link_libraries(gateway PRIVATE
    weblib Crow::Crow
    Threads::Threads
    gRPC::grpc++
)

include_directories(gateway PRIVATE ../../web-lib/src)

set(SOURCE_FILE ${CMAKE_SOURCE_DIR}/data/.env)
add_custom_command(TARGET gateway POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SOURCE_FILE} ${CMAKE_BINARY_DIR}/bin/.env
)

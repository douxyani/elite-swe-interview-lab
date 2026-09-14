cmake_minimum_required(VERSION 3.16)
project(batched_network_producer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(tests tests.cpp)
target_include_directories(tests PRIVATE .)

find_package(Threads REQUIRED)
target_link_libraries(tests PRIVATE Threads::Threads)

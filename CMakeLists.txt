cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(add VERSION 1.0)


add_executable(test_main tests/test_main.cpp)
target_include_directories(test_main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/rapidcheck")
target_link_libraries(test_main rapidcheck)

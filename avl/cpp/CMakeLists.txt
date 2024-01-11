cmake_minimum_required(VERSION 3.27)
project(avl23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++17 -ggdb3 -g")

SET(BUILD_GMOCK OFF)
SET(BUILD_GTEST ON)
add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

file(GLOB SOURCE_FILES ./src/*.cpp ./src/*.h ./src/*.hpp)
file(GLOB TEST_SOURCES tests/*.cpp)

add_executable(avl_exe ./main.cpp ${SOURCE_FILES})
add_executable(correrTests ${SOURCE_FILES} ${TEST_SOURCES})

target_link_libraries(correrTests gtest gtest_main)

add_test(correrTests avl_test)
cmake_minimum_required(VERSION 2.6)
project(fproject)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
add_subdirectory(test/googletest)
include_directories(test/googletest/include test/googletest)

set(SOURCE_FILES src/neurone.cpp src/simulation.cpp src/network.cpp src/Contants.h)
add_executable(fproject src/main.cpp ${SOURCE_FILES} )
add_executable(fproject_unittest test/unittest.cpp ${SOURCE_FILES} )

target_link_libraries(fproject_unittest gtest gtest_main)
add_test(fproject_unittest fproject_unittest)
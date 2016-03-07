cmake_minimum_required(VERSION 3.1)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test/basic_check.cpp src/FizzBuzz.h src/GoogleTestDemo.h)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(runBasicTests ${SOURCE_FILES})

target_link_libraries(runBasicTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
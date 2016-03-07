cmake_minimum_required(VERSION 3.1)

include_directories(/Users/martinkysel/work/googletest/googletest/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test/basic_check.cpp src/FizzBuzz.h src/GoogleTestDemo.h)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(runBasicTests ${SOURCE_FILES})

target_link_libraries(runBasicTests /Users/martinkysel/work/googletest/googletest/build/libgtest.a
        /Users/martinkysel/work/googletest/googletest/build/libgtest_main.a)
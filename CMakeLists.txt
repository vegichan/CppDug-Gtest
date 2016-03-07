cmake_minimum_required(VERSION 3.1)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
AUX_SOURCE_DIRECTORY(test GTEST_SOURCE_FILES)
AUX_SOURCE_DIRECTORY(src SOURCE_FILES)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(runBasicTests ${SOURCE_FILES} ${GTEST_SOURCE_FILES})

target_link_libraries(runBasicTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

FOREACH(GTEST_SOURCE_FILE ${GTEST_SOURCE_FILES})
    FILE(STRINGS ${GTEST_SOURCE_FILE} GTEST_NAMES REGEX ^TEST)
    FOREACH(GTEST_NAME ${GTEST_NAMES})
        STRING(REGEX REPLACE ["\) \(,"] ";" GTEST_NAME ${GTEST_NAME})
        LIST(GET GTEST_NAME 1 GTEST_GROUP_NAME)
        LIST(GET GTEST_NAME 3 GTEST_NAME)
        ADD_TEST(${GTEST_GROUP_NAME}.${GTEST_NAME}
                runBasicTests
                --gtest_filter=${GTEST_GROUP_NAME}.${GTEST_NAME})
    ENDFOREACH()
ENDFOREACH()
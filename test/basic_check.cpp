#include "gtest/gtest.h"
#include "../src/GoogleTestDemo.h"
#include "../src/FizzBuzz.h"

/* GTEST TESTS
 * execute using gtest*
 */

TEST(gtest, testTrue){
    EXPECT_TRUE(getTrue());
}
TEST(gtest, testFalse){
    EXPECT_FALSE(!getTrue());
}
TEST(gtest, testNoThrow){
    EXPECT_NO_THROW(throwEx(5));
}
TEST(gtest, testThrow){
    EXPECT_THROW(throwEx(-9), std::invalid_argument);
}
TEST(gtest, testEq){
    EXPECT_EQ(5, getFive());
}
TEST(gtest, testStrEq){
    std::string s1 = "abcd";
    std::string s2 = "abcd";
    EXPECT_STREQ(s1.c_str(), s2.c_str());
    EXPECT_EQ(s1, s2);
}
TEST(gtest, testFailure){
    EXPECT_EQ(1, 0);
}
// run all tests with --gtest_also_run_disabled_tests
TEST(gtest, DISABLED_testFailure2){
    EXPECT_EQ(1, 0);
}
// expectation continues but marks test as failed
TEST(gtest, testExpectation){
    EXPECT_EQ(0, 1);
    EXPECT_EQ(1, 1);
    EXPECT_EQ(2, 1);
}
// assertion breaks the test
TEST(gtest, testAssertion){
    ASSERT_EQ(0, 1);
    ASSERT_EQ(1, 1);
    ASSERT_EQ(2, 1);
}

//--gtest_repeat=1000, CLion can't deal with this param properly
TEST(gtest, testRandomness){
    EXPECT_NO_THROW(failInpredictably());
}


/* FizzBuzz TESTS
 * execute using testFizzBuzz.*:
 */


TEST(testFizzBuzz, basicCheck1) {
    EXPECT_EQ("1", getFizzBuzz(1));
}

/*************************************************************************
	> File Name: test_google.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Sep 2022 08:56:45 PM CST
 ************************************************************************/

#include<iostream>
#include<ktest/ktest.h>
using namespace std;

int add(int a, int b) {
    return a + b;
}
TEST(test1, add_function) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_NE(add(3, 4), 6);
    EXPECT_LT(add(3, 4), 8);
    EXPECT_LE(add(3, 4), 7);
    EXPECT_GT(add(3, 4), 6);
    EXPECT_GE(add(3, 4), 7);
}

TEST(test2, add_function) {
    EXPECT_EQ(add(3, 4), 6);
    EXPECT_NE(add(3, 4), 7);
    EXPECT_LT(add(3, 4), 6);
    EXPECT_LE(add(3, 4), 6);
    EXPECT_GT(add(3, 4), 8);
    EXPECT_GE(add(3, 4), 8);
}
int main() {
    return RUN_ALL_TESTS();
}

#include <gtest/gtest.h>
#include "mydeque.h"
#include <iostream>

// Demonstrate some basic assertions.
TEST(mydeque_test, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
    MyDeque que(5);
    que.push_head(10);
    que.push_tail(-1);
    auto ret = que.at(1);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), -1);
    que.push_head(15);
    ret = que.at(1);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 10);

    ret = que.pop_head();
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 15);
    ret = que.pop_tail();
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), -1);
}
TEST(mydeque_test, resize) {
    MyDeque que(5);
    for(int i = 0; i < 5; ++i) {
        if (i%2 == 1) {
            que.push_head(i); 
        } else {
            que.push_tail(i);
        }
        EXPECT_EQ(que.size(), i+1); 
    }
    auto ret = que.at(0);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 3); 

    ret = que.at(1);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 1); 

    ret = que.at(2);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 0); 
    ret = que.at(3);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 2); 
    ret = que.at(4);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 4); 
    // 3 1 0 2 4
    EXPECT_EQ(que.get_head(), -2);
    EXPECT_EQ(que.get_tail(), 3);
    que.push_head(10);
    EXPECT_EQ(que.get_resize_num(), 1);

    // 10 3 1 0 2 4 
    EXPECT_EQ(que.get_head(), -1);
    EXPECT_EQ(que.get_tail(), 5);
    EXPECT_EQ(que.size(), 6); 
    ret = que.at(0);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 10); 
    ret = que.at(1);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 3); 
    ret = que.at(2);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 1); 
    ret = que.at(3);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 0); 
    ret = que.at(4);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 2); 
    ret = que.at(5);
    EXPECT_TRUE(ret.has_value());
    EXPECT_EQ(ret.value(), 4); 
}

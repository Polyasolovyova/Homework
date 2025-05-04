#include <gtest/gtest.h>
#include "stack.h"


TEST(StackTest, PushTest) {
    Stack stack(3);
    stack.push(10);
    EXPECT_EQ(stack.top(), 10);
    stack.push(20);
    EXPECT_EQ(stack.top(), 20);
}


TEST(StackTest, PopTest) {
    Stack stack(3);
    stack.push(5);
    stack.push(15);
    stack.pop();
    EXPECT_EQ(stack.top(), 5);
    stack.pop();
    EXPECT_TRUE(stack.empty());
}


TEST(StackTest, TopTest) {
    Stack stack(3);
    stack.push(42);
    EXPECT_EQ(stack.top(), 42);
    stack.push(99);
    EXPECT_EQ(stack.top(), 99);
}


TEST(StackTest, EmptyTest) {
    Stack stack(3);
    EXPECT_TRUE(stack.empty());
    stack.push(1);
    EXPECT_FALSE(stack.empty());
}


TEST(StackTest, FullTest) {
    Stack stack(2);
    stack.push(7);
    stack.push(14);
    EXPECT_TRUE(stack.full());
}


TEST(StackTest, SizeTest) {
    Stack stack(5);
    EXPECT_EQ(stack.size(), 0);
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.size(), 2);
}




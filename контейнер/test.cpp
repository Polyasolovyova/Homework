#include "Container.h"
#include "Derived1.h"
#include "Derived2.h"
#include <gtest/gtest.h>

TEST(ContainerTest, AddElement) {
    Container container;
    container.add(new Derived1(10));
    EXPECT_NO_THROW(container.display_all());
}

TEST(ContainerTest, InsertElement) {
    Container container;
    container.add(new Derived1(5));
    container.insert(0, new Derived2("Hello"));
    EXPECT_NO_THROW(container.display_all());
}

TEST(ContainerTest, RemoveElement) {
    Container container;
    container.add(new Derived1(7));
    container.remove(0);
    EXPECT_NO_THROW(container.display_all());
}

TEST(ContainerTest, DisplayOneElement) {
    Container container;
    container.add(new Derived2("Test"));
    EXPECT_NO_THROW(container.display_one(0));
}

TEST(ContainerTest, ClearContainer) {
    Container container;
    container.add(new Derived1(3));
    container.clear();
    EXPECT_NO_THROW(container.display_all());
}

TEST(ContainerTest, InvalidInsert) {
    Container container;
    EXPECT_NO_THROW(container.insert(-1, new Derived1(5)));
}

TEST(ContainerTest, InvalidRemove) {
    Container container;
    EXPECT_NO_THROW(container.remove(10));
}

TEST(ContainerTest, EmptyContainerDisplay) {
    Container container;
    EXPECT_NO_THROW(container.display_all());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

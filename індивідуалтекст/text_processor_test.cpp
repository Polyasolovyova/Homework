#include "text_processor.h"
#include <gtest/gtest.h>
#include <cstring>


TEST(ProcessTextTest, ReplaceFirstDigitGroup) {
    char text[] = "abc123def456";
    processText(text);
    EXPECT_STREQ(text, "abc***def456");
}


TEST(ProcessTextTest, StartsWithUppercase) {
    char text[] = "Abc123def456";
    processText(text);
    EXPECT_STREQ(text, "Abc123def456");
}


TEST(ProcessTextTest, StartsWithDigit) {
    char text[] = "123abc456";
    processText(text);
    EXPECT_STREQ(text, "123abc456");
}


TEST(ProcessTextTest, NoDigitsAfterLetters) {
    char text[] = "abc-def123";
    processText(text);
    EXPECT_STREQ(text, "abc-def123");
}


TEST(ProcessTextTest, EmptyString) {
    char text[] = "";
    processText(text);
    EXPECT_STREQ(text, "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

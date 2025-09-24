#include <gtest/gtest.h>
#include "../include/Utils.h"

class UtilsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // No setup needed for Utils
    }

    void TearDown() override {
        // No cleanup needed for Utils
    }
};

// Test RandomInt method
TEST_F(UtilsTest, RandomIntMethod) {
    // Test multiple random numbers to ensure they're in range
    for (int i = 0; i < 100; ++i) {
        int random = Utils::RandomInt(1, 10);
        EXPECT_GE(random, 1);
        EXPECT_LE(random, 10);
    }
}

// Test RandomInt with same min and max
TEST_F(UtilsTest, RandomIntSameMinMax) {
    int random = Utils::RandomInt(5, 5);
    EXPECT_EQ(random, 5);
}

// Test RandomInt with reverse range
TEST_F(UtilsTest, RandomIntReverseRange) {
    // This should handle the case where min > max
    (void)Utils::RandomInt(10, 1); // Suppress unused variable warning
    // The function should still work, but we can't predict the exact behavior
    // We just ensure it doesn't crash
    SUCCEED();
}

// Test Trim method with spaces
TEST_F(UtilsTest, TrimMethodWithSpaces) {
    std::string input = "  hello world  ";
    std::string result = Utils::Trim(input);
    
    EXPECT_EQ(result, "hello world");
}

// Test Trim method with tabs
TEST_F(UtilsTest, TrimMethodWithTabs) {
    std::string input = "\thello world\t";
    std::string result = Utils::Trim(input);
    
    EXPECT_EQ(result, "hello world");
}

// Test Trim method with mixed whitespace
TEST_F(UtilsTest, TrimMethodWithMixedWhitespace) {
    std::string input = " \t hello world \t ";
    std::string result = Utils::Trim(input);
    
    EXPECT_EQ(result, "hello world");
}

// Test Trim method with no whitespace
TEST_F(UtilsTest, TrimMethodWithNoWhitespace) {
    std::string input = "hello world";
    std::string result = Utils::Trim(input);
    
    EXPECT_EQ(result, "hello world");
}

// Test Trim method with only whitespace
TEST_F(UtilsTest, TrimMethodWithOnlyWhitespace) {
    std::string input = "   \t  ";
    std::string result = Utils::Trim(input);
    
    EXPECT_EQ(result, "");
}

// Test Trim method with empty string
TEST_F(UtilsTest, TrimMethodWithEmptyString) {
    std::string input = "";
    std::string result = Utils::Trim(input);
    
    EXPECT_EQ(result, "");
}

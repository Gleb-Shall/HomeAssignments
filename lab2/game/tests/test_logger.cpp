#include <gtest/gtest.h>
#include "../include/Logger.h"

class LoggerTest : public ::testing::Test {
protected:
    void SetUp() override {
        logger = new Logger();
    }

    void TearDown() override {
        delete logger;
    }

    Logger* logger;
};

// Test Logger Log method
TEST_F(LoggerTest, LoggerLogMethod) {
    // Log method should not crash
    logger->Log("Test message");
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Logger Log with different message types
TEST_F(LoggerTest, LoggerLogDifferentMessageTypes) {
    logger->Log("Info message");
    logger->Log("Warning message");
    logger->Log("Error message");
    logger->Log("Debug message");
    
    // All should not crash
    SUCCEED();
}

// Test Logger Log with empty message
TEST_F(LoggerTest, LoggerLogEmptyMessage) {
    logger->Log("");
    
    // Should not crash
    SUCCEED();
}

// Test Logger Log with special characters
TEST_F(LoggerTest, LoggerLogSpecialCharacters) {
    logger->Log("Message with special chars: !@#$%^&*()");
    logger->Log("Message with newlines:\nLine 2\nLine 3");
    logger->Log("Message with tabs:\tTabbed text");
    
    // All should not crash
    SUCCEED();
}

// Test Logger Log with long message
TEST_F(LoggerTest, LoggerLogLongMessage) {
    std::string longMessage = "This is a very long message that contains many characters and should test the logger's ability to handle long strings without crashing or causing any issues.";
    
    logger->Log(longMessage);
    
    // Should not crash
    SUCCEED();
}

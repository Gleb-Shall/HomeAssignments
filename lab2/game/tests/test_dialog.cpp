#include <gtest/gtest.h>
#include "../include/Dialog.h"

class DialogTest : public ::testing::Test {
protected:
    void SetUp() override {
        dialog = new Dialog();
    }

    void TearDown() override {
        delete dialog;
    }

    Dialog* dialog;
};

// Test Dialog Show method
TEST_F(DialogTest, DialogShowMethod) {
    // Show method should not crash
    dialog->Show();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Dialog NextLine method
TEST_F(DialogTest, DialogNextLineMethod) {
    dialog->NextLine();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Dialog HasChoices method
TEST_F(DialogTest, DialogHasChoicesMethod) {
    EXPECT_FALSE(dialog->HasChoices());
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Dialog SelectChoice method
TEST_F(DialogTest, DialogSelectChoiceMethod) {
    dialog->SelectChoice(0);
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Dialog AddChoice method
TEST_F(DialogTest, DialogAddChoiceMethod) {
    dialog->AddChoice("Option 1");
    dialog->AddChoice("Option 2");
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Dialog SetText method
TEST_F(DialogTest, DialogSetTextMethod) {
    dialog->SetText("New dialog text");
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

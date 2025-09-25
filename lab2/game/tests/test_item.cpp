#include <gtest/gtest.h>
#include "../include/Item.h"
#include "../include/Player.h"

class ItemTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
    }

    void TearDown() override {
        delete player;
    }

    Player* player;
};

// Test Item constructor and basic properties
TEST_F(ItemTest, ItemConstructor) {
    Item item("Test Item", "A test item", 10);
    
    EXPECT_EQ(item.GetName(), "Test Item");
    EXPECT_EQ(item.GetDescription(), "A test item");
    EXPECT_EQ(item.GetValue(), 10);
}

// Test Item getters
TEST_F(ItemTest, ItemGetters) {
    Item item("Test Item", "A test item", 10);
    
    EXPECT_EQ(item.GetName(), "Test Item");
    EXPECT_EQ(item.GetDescription(), "A test item");
    EXPECT_EQ(item.GetValue(), 10);
}

// Test Item Use method (should be overridden by derived classes)
TEST_F(ItemTest, ItemUseMethod) {
    Item item("Test Item", "A test item", 10);
    
    // Use method should not crash
    item.Use(*player);
    
    // Since it's a base class, it should just print a message
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

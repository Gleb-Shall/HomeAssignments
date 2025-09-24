#include <gtest/gtest.h>
#include "../include/Armor.h"
#include "../include/Player.h"

class ArmorClassTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
    }

    void TearDown() override {
        delete player;
    }

    Player* player;
};

// Test Armor constructor
TEST_F(ArmorClassTest, ArmorConstructor) {
    Armor armor("Leather Armor", "Basic leather armor", 15, 5);
    
    EXPECT_EQ(armor.GetName(), "Leather Armor");
    EXPECT_EQ(armor.GetDescription(), "Basic leather armor");
    EXPECT_EQ(armor.GetValue(), 15);
    EXPECT_EQ(armor.GetDefense(), 5);
}

// Test Armor defense getter
TEST_F(ArmorClassTest, ArmorDefenseProperties) {
    Armor armor("Test Armor", "Test armor", 10, 8);
    
    EXPECT_EQ(armor.GetDefense(), 8);
}

// Test Armor Use method (which now handles equipping)
TEST_F(ArmorClassTest, ArmorUseMethod) {
    Armor armor("Test Armor", "Test armor", 10, 5);
    
    // Use method should not crash
    armor.Use(*player);
    
    // Use method just prints message, doesn't actually equip
    SUCCEED();
}

// Test different armor types
TEST_F(ArmorClassTest, DifferentArmorTypes) {
    Armor leather("Leather Armor", "Basic armor", 15, 5);
    Armor chain("Chain Mail", "Better armor", 25, 10);
    Armor plate("Plate Armor", "Best armor", 50, 20);
    
    EXPECT_EQ(leather.GetDefense(), 5);
    EXPECT_EQ(chain.GetDefense(), 10);
    EXPECT_EQ(plate.GetDefense(), 20);
}

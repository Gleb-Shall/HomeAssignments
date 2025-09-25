#include <gtest/gtest.h>
#include "../include/Weapon.h"
#include "../include/Player.h"

class WeaponTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
    }

    void TearDown() override {
        delete player;
    }

    Player* player;
};

// Test Weapon constructor
TEST_F(WeaponTest, WeaponConstructor) {
    Weapon weapon("Iron Sword", "A sharp iron sword", 10, 15);
    
    EXPECT_EQ(weapon.GetName(), "Iron Sword");
    EXPECT_EQ(weapon.GetDescription(), "A sharp iron sword");
    EXPECT_EQ(weapon.GetValue(), 10);
    EXPECT_EQ(weapon.GetDamage(), 15);
}

// Test Weapon damage getter
TEST_F(WeaponTest, WeaponDamageProperties) {
    Weapon weapon("Test Sword", "A test sword", 5, 10);
    
    EXPECT_EQ(weapon.GetDamage(), 10);
}

// Test Weapon Use method (which now handles equipping)
TEST_F(WeaponTest, WeaponUseMethod) {
    Weapon weapon("Test Sword", "A test sword", 5, 10);
    
    // Use method should not crash
    weapon.Use(*player);
    
    // Use method just prints message, doesn't actually equip
    SUCCEED();
}

// Test different weapon types
TEST_F(WeaponTest, DifferentWeaponTypes) {
    Weapon sword("Sword", "A sword", 10, 15);
    Weapon dagger("Dagger", "A dagger", 5, 8);
    Weapon axe("Axe", "An axe", 12, 20);
    
    EXPECT_EQ(sword.GetDamage(), 15);
    EXPECT_EQ(dagger.GetDamage(), 8);
    EXPECT_EQ(axe.GetDamage(), 20);
}

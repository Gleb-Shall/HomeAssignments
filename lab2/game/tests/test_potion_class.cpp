#include <gtest/gtest.h>
#include "../include/Potion.h"
#include "../include/Player.h"

class PotionClassTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
    }

    void TearDown() override {
        delete player;
    }

    Player* player;
};

// Test Potion constructor
TEST_F(PotionClassTest, PotionConstructor) {
    Potion potion("Health Potion", "Restores health", 5, "heal", 20);
    
    EXPECT_EQ(potion.GetName(), "Health Potion");
    EXPECT_EQ(potion.GetDescription(), "Restores health");
    EXPECT_EQ(potion.GetValue(), 5);
    EXPECT_EQ(potion.GetEffect(), "heal");
    // Note: GetPower() method doesn't exist in Potion class
}

// Test Potion effect and power properties
TEST_F(PotionClassTest, PotionEffectAndPower) {
    Potion potion("Test Potion", "Test potion", 10, "mana", 30);
    
    EXPECT_EQ(potion.GetEffect(), "mana");
    // Note: GetPower() method doesn't exist in Potion class
    // We can only test GetEffect()
}

// Test Potion Use method
TEST_F(PotionClassTest, PotionUseMethod) {
    Potion healPotion("Health Potion", "Restores health", 5, "heal", 20);
    
    int initialHP = player->GetHP();
    player->TakeDamage(30); // Damage player
    
    healPotion.Use(*player);
    
    // Player should be healed
    EXPECT_GT(player->GetHP(), initialHP - 30);
}

// Test different potion types
TEST_F(PotionClassTest, DifferentPotionTypes) {
    Potion healPotion("Health Potion", "Restores health", 5, "heal", 20);
    Potion manaPotion("Mana Potion", "Restores mana", 8, "mana", 30);
    Potion strengthPotion("Strength Potion", "Increases strength", 15, "strength", 10);
    
    EXPECT_EQ(healPotion.GetEffect(), "heal");
    EXPECT_EQ(manaPotion.GetEffect(), "mana");
    EXPECT_EQ(strengthPotion.GetEffect(), "strength");
}

// Test potion expiration
TEST_F(PotionClassTest, PotionExpiration) {
    Potion potion("Test Potion", "Test potion", 5, "heal", 20);
    
    EXPECT_FALSE(potion.IsExpired());
    
    // Note: SetExpired() method doesn't exist in Potion class
    // We can only test IsExpired() which should return false by default
}

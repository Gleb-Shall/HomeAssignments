#include <gtest/gtest.h>
#include "../include/Player.h"

class HealSpellTest : public ::testing::Test {
protected:
    Player* player;

    void SetUp() override {
        player = new Player();
    }

    void TearDown() override {
        delete player;
    }
};

// Test that Heal spell heals to full HP
TEST_F(HealSpellTest, HealSpellHealsToFull) {
    // Damage player first
    player->TakeDamage(50);
    int damagedHP = player->GetHP();
    EXPECT_LT(damagedHP, player->GetMaxHp()) << "Player should be damaged";
    
    // Heal to full
    int healAmount = player->GetMaxHp() - player->GetHP();
    player->Heal(healAmount);
    
    EXPECT_EQ(player->GetHP(), player->GetMaxHp()) << "Heal should restore full HP";
}

// Test that Heal doesn't exceed max HP
TEST_F(HealSpellTest, HealDoesNotExceedMaxHP) {
    // Try to heal when already at full HP
    int initialHP = player->GetHP();
    player->Heal(1000); // Try to heal way more than max
    
    EXPECT_EQ(player->GetHP(), player->GetMaxHp()) << "Heal should not exceed max HP";
    EXPECT_EQ(player->GetHP(), initialHP) << "HP should remain unchanged when already at max";
}

// Test partial healing
TEST_F(HealSpellTest, PartialHealing) {
    // Damage player
    player->TakeDamage(30);
    int damagedHP = player->GetHP();
    
    // Heal partially
    player->Heal(15);
    
    EXPECT_EQ(player->GetHP(), damagedHP + 15) << "Partial heal should work correctly";
    EXPECT_LT(player->GetHP(), player->GetMaxHp()) << "Should not exceed max HP";
}

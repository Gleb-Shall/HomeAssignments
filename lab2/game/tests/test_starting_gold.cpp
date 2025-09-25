#include <gtest/gtest.h>
#include "../include/Player.h"

class StartingGoldTest : public ::testing::Test {
protected:
    Player* player;

    void SetUp() override {
        player = new Player();
    }

    void TearDown() override {
        delete player;
    }
};

// Test that player starts with 100 gold
TEST_F(StartingGoldTest, PlayerStartsWith100Gold) {
    EXPECT_EQ(player->GetGold(), 100) << "Player should start with 100 gold";
}

// Test gold can be added and subtracted
TEST_F(StartingGoldTest, GoldCanBeModified) {
    int initialGold = player->GetGold();
    
    // Add gold
    player->AddGold(50);
    EXPECT_EQ(player->GetGold(), initialGold + 50) << "Gold should increase by 50";
    
    // Subtract gold
    player->AddGold(-30);
    EXPECT_EQ(player->GetGold(), initialGold + 20) << "Gold should decrease by 30";
}

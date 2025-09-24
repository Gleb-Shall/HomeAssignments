#include <gtest/gtest.h>
#include "../include/NPC.h"
#include "../include/Player.h"

class NPCTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        npc = new NPC("Test NPC", "A test NPC");
    }

    void TearDown() override {
        delete player;
        delete npc;
    }

    Player* player;
    NPC* npc;
};

// Test NPC constructor
TEST_F(NPCTest, NPCConstructor) {
    EXPECT_EQ(npc->GetName(), "Test NPC");
    // Note: GetDescription() method doesn't exist in NPC class
    // We can only test GetName()
}

// Test NPC Talk method
TEST_F(NPCTest, NPCTalkMethod) {
    // Talk method should not crash
    npc->Talk();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test NPC GiveQuest method
TEST_F(NPCTest, NPCGiveQuestMethod) {
    // GiveQuest method should not crash
    npc->GiveQuest();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test NPC with different names
TEST_F(NPCTest, NPCDifferentNames) {
    NPC merchant("Merchant", "A friendly merchant");
    NPC guard("Guard", "A town guard");
    NPC wizard("Wizard", "A powerful wizard");
    
    EXPECT_EQ(merchant.GetName(), "Merchant");
    EXPECT_EQ(guard.GetName(), "Guard");
    EXPECT_EQ(wizard.GetName(), "Wizard");
    
    // Note: GetDescription() method doesn't exist in NPC class
    // We can only test GetName()
}

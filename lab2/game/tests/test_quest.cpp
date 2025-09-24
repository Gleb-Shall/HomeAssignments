#include <gtest/gtest.h>
#include "../include/Quest.h"
#include "../include/Player.h"

class QuestTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        quest = new Quest("A test quest", 50);
    }

    void TearDown() override {
        delete player;
        delete quest;
    }

    Player* player;
    Quest* quest;
};

// Test Quest constructor
TEST_F(QuestTest, QuestConstructor) {
    EXPECT_EQ(quest->GetDescription(), "A test quest");
    // Note: GetName() method doesn't exist in Quest class
    // We can only test GetDescription()
}

// Test Quest Complete method
TEST_F(QuestTest, QuestCompleteMethod) {
    // Start the quest first
    quest->Complete(*player); // This should start and complete the quest
    EXPECT_TRUE(quest->IsCompleted());
    EXPECT_EQ(player->GetGold(), 100 + 50); // Initial gold + reward
}


// Test Quest with different descriptions
TEST_F(QuestTest, QuestDifferentDescriptions) {
    Quest mainQuest("The main story quest", 100);
    Quest sideQuest("An optional side quest", 50);
    Quest fetchQuest("Bring me 10 items", 25);
    
    EXPECT_EQ(mainQuest.GetDescription(), "The main story quest");
    EXPECT_EQ(sideQuest.GetDescription(), "An optional side quest");
    EXPECT_EQ(fetchQuest.GetDescription(), "Bring me 10 items");
    
    // Note: GetName() method doesn't exist in Quest class
    // We can only test GetDescription()
}

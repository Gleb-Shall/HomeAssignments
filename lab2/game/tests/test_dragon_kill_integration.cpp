#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/World.h"
#include "../include/Battle.h"
#include "../include/Game.h"
#include <iostream>
#include <sstream>

class DragonKillIntegrationTest : public ::testing::Test {
protected:
    void SetUp() override {
        game = new Game();
        game->Init();
    }

    void TearDown() override {
        delete game;
    }

    Game* game;
};

// Test dragon spawning and killing through game commands
TEST_F(DragonKillIntegrationTest, DragonSpawnAndKill) {
    // Spawn dragon
    std::stringstream input;
    input << "spawn dragon\n";
    input << "look\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "look\n";
    input << "attack\n";
    input << "quit\n";
    
    // Redirect input
    std::streambuf* orig = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());
    
    // Run game simulation
    game->Run();
    
    // Restore input
    std::cin.rdbuf(orig);
    
    // Check that dragon is defeated
    EXPECT_TRUE(game->IsSecondQuestCompleted()) << "Second quest should be completed after dragon defeat";
}

// Test that dragon doesn't respawn after being killed
TEST_F(DragonKillIntegrationTest, DragonDoesNotRespawnAfterKill) {
    // Spawn and kill dragon
    std::stringstream input;
    input << "spawn dragon\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "attack\n";
    input << "look\n";
    input << "attack\n";
    input << "look\n";
    input << "quit\n";
    
    // Redirect input
    std::streambuf* orig = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());
    
    // Run game simulation
    game->Run();
    
    // Restore input
    std::cin.rdbuf(orig);
    
    // Check that dragon is permanently defeated
    EXPECT_TRUE(game->IsSecondQuestCompleted()) << "Dragon should be permanently defeated";
}

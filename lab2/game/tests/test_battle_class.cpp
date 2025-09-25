#include <gtest/gtest.h>
#include "../include/Battle.h"
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/World.h"

class BattleClassTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        enemy = new Enemy();
        world = new World();
        battle = new Battle();
        world->Generate();
    }

    void TearDown() override {
        delete player;
        delete enemy;
        delete world;
        delete battle;
    }

    Player* player;
    Enemy* enemy;
    World* world;
    Battle* battle;
};

// Test Battle Start method
TEST_F(BattleClassTest, BattleStartMethod) {
    world->SpawnEnemy();
    
    battle->Start(*player, *enemy, *world);
    
    EXPECT_TRUE(battle->IsActive());
}

// Test Battle Start without enemy on map
TEST_F(BattleClassTest, BattleStartWithoutEnemy) {
    // Don't spawn enemy
    battle->Start(*player, *enemy, *world);
    
    EXPECT_FALSE(battle->IsActive());
}

// Test Battle PlayerTurn method
TEST_F(BattleClassTest, BattlePlayerTurnMethod) {
    world->SpawnEnemy();
    battle->Start(*player, *enemy, *world);
    
    int initialEnemyHP = enemy->GetHP();
    battle->PlayerTurn();
    
    EXPECT_LT(enemy->GetHP(), initialEnemyHP);
}

// Test Battle EnemyTurn method
TEST_F(BattleClassTest, BattleEnemyTurnMethod) {
    world->SpawnEnemy();
    battle->Start(*player, *enemy, *world);
    
    int initialPlayerHP = player->GetHP();
    battle->EnemyTurn();
    
    EXPECT_LT(player->GetHP(), initialPlayerHP);
}

// Test Battle CheckWin method - enemy dead
TEST_F(BattleClassTest, BattleCheckWinEnemyDead) {
    world->SpawnEnemy();
    battle->Start(*player, *enemy, *world);
    
    // Kill enemy
    enemy->TakeDamage(enemy->GetHP());
    
    EXPECT_TRUE(battle->CheckWin());
}

// Test Battle CheckWin method - player dead
TEST_F(BattleClassTest, BattleCheckWinPlayerDead) {
    world->SpawnEnemy();
    battle->Start(*player, *enemy, *world);
    
    // Kill player
    player->TakeDamage(player->GetHP());
    
    EXPECT_TRUE(battle->CheckWin());
}

// Test Battle CheckWin method - no one dead
TEST_F(BattleClassTest, BattleCheckWinNoOneDead) {
    world->SpawnEnemy();
    battle->Start(*player, *enemy, *world);
    
    // Don't kill anyone
    EXPECT_FALSE(battle->CheckWin());
}

// Test Battle End method
TEST_F(BattleClassTest, BattleEndMethod) {
    world->SpawnEnemy();
    battle->Start(*player, *enemy, *world);
    
    EXPECT_TRUE(battle->IsActive());
    
    battle->End();
    
    EXPECT_FALSE(battle->IsActive());
}

// Test Battle with dragon
TEST_F(BattleClassTest, BattleWithDragon) {
    world->SpawnDragon();
    Enemy dragon(150, 25);
    dragon.SetMagical(true);
    
    battle->Start(*player, dragon, *world);
    
    EXPECT_TRUE(battle->IsActive());
    EXPECT_TRUE(world->HasDragon());
}

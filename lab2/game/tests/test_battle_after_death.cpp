#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/World.h"
#include "../include/Battle.h"
#include <iostream>

class BattleAfterDeathTest : public ::testing::Test {
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

// Test that battle cannot start when no enemy is on map
TEST_F(BattleAfterDeathTest, CannotStartBattleWhenNoEnemyOnMap) {
    // Ensure no enemy is on map
    world->ClearMainEnemy();
    world->ClearDragon();
    
    // Try to start battle
    battle->Start(*player, *enemy, *world);
    
    // Verify battle state
    EXPECT_FALSE(battle->IsActive()) << "Battle should not be active when no enemy on map";
}

// Test that battle can start when enemy is on map
TEST_F(BattleAfterDeathTest, CanStartBattleWhenEnemyOnMap) {
    // Spawn enemy on map
    world->SpawnEnemy();
    
    // Start battle
    battle->Start(*player, *enemy, *world);
    
    // Verify battle is active
    EXPECT_TRUE(battle->IsActive()) << "Battle should be active when enemy is on map";
}

// Test that after enemy death, new battle cannot start
TEST_F(BattleAfterDeathTest, CannotStartNewBattleAfterEnemyDeath) {
    // Spawn enemy
    world->SpawnEnemy();
    
    // Start first battle
    battle->Start(*player, *enemy, *world);
    EXPECT_TRUE(battle->IsActive()) << "First battle should be active";
    
    // Kill enemy
    while (!enemy->IsDead()) {
        player->Attack(*enemy);
    }
    
    // End battle and clear enemy from map
    battle->End();
    world->ClearMainEnemy();
    
    // Create new enemy object (simulating what happens in Game.cpp)
    Enemy newEnemy;
    
    // Try to start new battle
    Battle newBattle;
    newBattle.Start(*player, newEnemy, *world);
    
    // Verify new battle cannot start because no enemy on map
    EXPECT_FALSE(newBattle.IsActive()) << "New battle should not start after enemy is cleared from map";
}

// Test dragon battle scenario
TEST_F(BattleAfterDeathTest, CannotStartBattleAfterDragonDeath) {
    // Spawn dragon
    world->SpawnDragon();
    
    // Start battle with dragon
    Enemy dragon(150, 25);
    dragon.SetMagical(true);
    battle->Start(*player, dragon, *world);
    EXPECT_TRUE(battle->IsActive()) << "Dragon battle should be active";
    
    // Kill dragon
    while (!dragon.IsDead()) {
        player->Attack(dragon);
    }
    
    // End battle and clear dragon from map
    battle->End();
    world->ClearDragon();
    
    // Try to start new battle
    Enemy newEnemy;
    Battle newBattle;
    newBattle.Start(*player, newEnemy, *world);
    
    // Verify new battle cannot start
    EXPECT_FALSE(newBattle.IsActive()) << "New battle should not start after dragon is cleared from map";
}

// Test that enemy object is properly reset after death
TEST_F(BattleAfterDeathTest, EnemyObjectResetAfterDeath) {
    // Spawn enemy
    world->SpawnEnemy();
    
    // Start battle
    battle->Start(*player, *enemy, *world);
    
    // Kill enemy
    while (!enemy->IsDead()) {
        player->Attack(*enemy);
    }
    
    // End battle and clear from map
    battle->End();
    world->ClearMainEnemy();
    
    // Create new enemy object (simulating Game.cpp behavior)
    Enemy newEnemy;
    
    // Verify new enemy is fresh
    EXPECT_FALSE(newEnemy.IsDead()) << "New enemy should not be dead";
    EXPECT_EQ(newEnemy.GetHP(), 50) << "New enemy should have default HP";
    EXPECT_FALSE(newEnemy.IsMagical()) << "New enemy should not be magical";
}

// Test multiple enemy spawns and deaths
TEST_F(BattleAfterDeathTest, MultipleEnemySpawnsAndDeaths) {
    for (int i = 0; i < 3; ++i) {
        // Spawn enemy
        world->SpawnEnemy();
        EXPECT_TRUE(world->HasEnemy()) << "Enemy should be spawned in iteration " << i;
        
        // Start battle
        battle->Start(*player, *enemy, *world);
        EXPECT_TRUE(battle->IsActive()) << "Battle should be active in iteration " << i;
        
        // Kill enemy
        while (!enemy->IsDead()) {
            player->Attack(*enemy);
        }
        
        // End battle and clear
        battle->End();
        world->ClearMainEnemy();
        
        // Verify enemy is cleared
        EXPECT_FALSE(world->HasEnemy()) << "Enemy should be cleared in iteration " << i;
        
        // Create new enemy for next iteration
        enemy = new Enemy();
    }
}

// Test that world state is properly managed
TEST_F(BattleAfterDeathTest, WorldStateManagement) {
    // Initially no enemies
    EXPECT_FALSE(world->HasEnemy()) << "Should have no enemy initially";
    EXPECT_FALSE(world->HasDragon()) << "Should have no dragon initially";
    
    // Spawn enemy
    world->SpawnEnemy();
    EXPECT_TRUE(world->HasEnemy()) << "Should have enemy after spawn";
    
    // Clear enemy
    world->ClearMainEnemy();
    EXPECT_FALSE(world->HasEnemy()) << "Should have no enemy after clear";
    
    // Spawn dragon
    world->SpawnDragon();
    EXPECT_TRUE(world->HasDragon()) << "Should have dragon after spawn";
    
    // Clear dragon
    world->ClearDragon();
    EXPECT_FALSE(world->HasDragon()) << "Should have no dragon after clear";
}

// Test battle state transitions
TEST_F(BattleAfterDeathTest, BattleStateTransitions) {
    // Initially no battle
    EXPECT_FALSE(battle->IsActive()) << "Battle should not be active initially";
    
    // Spawn enemy and start battle
    world->SpawnEnemy();
    battle->Start(*player, *enemy, *world);
    EXPECT_TRUE(battle->IsActive()) << "Battle should be active after start";
    
    // End battle
    battle->End();
    EXPECT_FALSE(battle->IsActive()) << "Battle should not be active after end";
    
    // Clear enemy
    world->ClearMainEnemy();
    EXPECT_FALSE(world->HasEnemy()) << "Enemy should be cleared";
    
    // Try to start new battle
    Enemy newEnemy;
    Battle newBattle;
    newBattle.Start(*player, newEnemy, *world);
    EXPECT_FALSE(newBattle.IsActive()) << "New battle should not start without enemy on map";
}

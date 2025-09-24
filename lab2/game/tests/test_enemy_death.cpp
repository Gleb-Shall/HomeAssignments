#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/World.h"
#include <iostream>

class EnemyDeathTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        enemy = new Enemy();
        world = new World();
        world->Generate();
    }

    void TearDown() override {
        delete player;
        delete enemy;
        delete world;
    }

    Player* player;
    Enemy* enemy;
    World* world;
};

// Test that enemy is completely reset after death
TEST_F(EnemyDeathTest, EnemyResetAfterDeath) {
    // Damage enemy to death
    while (!enemy->IsDead()) {
        player->Attack(*enemy);
    }
    
    // Verify enemy is dead
    EXPECT_TRUE(enemy->IsDead()) << "Enemy should be dead";
    EXPECT_EQ(enemy->GetHP(), 0) << "Enemy HP should be 0";
    
    // Reset enemy
    enemy->Reset();
    
    // Verify enemy is fully reset
    EXPECT_FALSE(enemy->IsDead()) << "Enemy should not be dead after reset";
    EXPECT_EQ(enemy->GetHP(), 50) << "Enemy HP should be reset to 50";
    EXPECT_FALSE(enemy->IsMagical()) << "Enemy should not be magical after reset";
    EXPECT_FALSE(enemy->HasBuff()) << "Enemy should not have buff after reset";
}

// Test that dragon disappears from map after death
TEST_F(EnemyDeathTest, DragonDisappearsFromMap) {
    // Spawn dragon
    world->SpawnDragon();
    
    // Verify dragon is on map
    EXPECT_TRUE(world->HasDragon()) << "Dragon should be spawned";
    EXPECT_EQ(world->GetDragonX(), 5) << "Dragon should be at x=5";
    EXPECT_EQ(world->GetDragonY(), 5) << "Dragon should be at y=5";
    
    // Clear dragon from map
    world->ClearDragon();
    
    // Verify dragon is removed from map
    EXPECT_FALSE(world->HasDragon()) << "Dragon should be removed from map";
    EXPECT_EQ(world->GetDragonX(), -1) << "Dragon X should be reset to -1";
    EXPECT_EQ(world->GetDragonY(), -1) << "Dragon Y should be reset to -1";
}

// Test that regular enemy disappears from map after death
TEST_F(EnemyDeathTest, RegularEnemyDisappearsFromMap) {
    // Spawn enemy
    world->SpawnEnemy();
    
    // Verify enemy is on map
    EXPECT_TRUE(world->HasEnemy()) << "Enemy should be spawned";
    EXPECT_GE(world->GetEnemyX(), 0) << "Enemy X should be valid";
    EXPECT_GE(world->GetEnemyY(), 0) << "Enemy Y should be valid";
    
    // Clear enemy from map
    world->ClearMainEnemy();
    
    // Verify enemy is removed from map
    EXPECT_FALSE(world->HasEnemy()) << "Enemy should be removed from map";
    EXPECT_EQ(world->GetEnemyX(), -1) << "Enemy X should be reset to -1";
    EXPECT_EQ(world->GetEnemyY(), -1) << "Enemy Y should be reset to -1";
}

// Test that enemy can be fought again after reset
TEST_F(EnemyDeathTest, EnemyCanBeFoughtAgainAfterReset) {
    // Damage enemy to death
    while (!enemy->IsDead()) {
        player->Attack(*enemy);
    }
    
    // Verify enemy is dead
    EXPECT_TRUE(enemy->IsDead()) << "Enemy should be dead";
    
    // Reset enemy
    enemy->Reset();
    
    // Verify enemy can be fought again
    EXPECT_FALSE(enemy->IsDead()) << "Enemy should not be dead after reset";
    
    // Attack enemy again
    player->Attack(*enemy);
    EXPECT_LT(enemy->GetHP(), 50) << "Enemy should take damage after reset";
}

// Test dragon state after being defeated
TEST_F(EnemyDeathTest, DragonStateAfterDefeat) {
    // Spawn dragon
    world->SpawnDragon();
    
    // Set dragon as defeated
    world->SetDragonDefeated(true);
    
    // Verify dragon is marked as defeated
    EXPECT_TRUE(world->IsDragonDefeated()) << "Dragon should be marked as defeated";
    
    // Clear dragon
    world->ClearDragon();
    
    // Verify dragon is completely removed
    EXPECT_FALSE(world->HasDragon()) << "Dragon should be removed from map";
    EXPECT_TRUE(world->IsDragonDefeated()) << "Dragon should still be marked as defeated";
}

// Test multiple enemy resets
TEST_F(EnemyDeathTest, MultipleEnemyResets) {
    for (int i = 0; i < 3; ++i) {
        // Damage enemy to death
        while (!enemy->IsDead()) {
            player->Attack(*enemy);
        }
        
        // Verify enemy is dead
        EXPECT_TRUE(enemy->IsDead()) << "Enemy should be dead in iteration " << i;
        
        // Reset enemy
        enemy->Reset();
        
        // Verify enemy is fully reset
        EXPECT_FALSE(enemy->IsDead()) << "Enemy should not be dead after reset in iteration " << i;
        EXPECT_EQ(enemy->GetHP(), 50) << "Enemy HP should be 50 after reset in iteration " << i;
    }
}

// Test enemy with magical properties reset
TEST_F(EnemyDeathTest, MagicalEnemyReset) {
    // Create magical enemy
    Enemy magicalEnemy(150, 25);
    magicalEnemy.SetMagical(true);
    
    // Verify magical properties
    EXPECT_TRUE(magicalEnemy.IsMagical()) << "Enemy should be magical";
    EXPECT_EQ(magicalEnemy.GetHP(), 150) << "Magical enemy should have 150 HP";
    
    // Damage to death
    while (!magicalEnemy.IsDead()) {
        player->Attack(magicalEnemy);
    }
    
    // Reset magical enemy
    magicalEnemy.Reset();
    
    // Verify reset to default values
    EXPECT_FALSE(magicalEnemy.IsMagical()) << "Enemy should not be magical after reset";
    EXPECT_EQ(magicalEnemy.GetHP(), 50) << "Enemy HP should be reset to 50";
}

// Test that enemy position is properly cleared
TEST_F(EnemyDeathTest, EnemyPositionCleared) {
    // Spawn enemy at specific position
    world->SpawnEnemyAt(3, 3);
    
    // Verify enemy position
    EXPECT_TRUE(world->HasEnemy()) << "Enemy should be spawned";
    EXPECT_EQ(world->GetEnemyX(), 3) << "Enemy should be at x=3";
    EXPECT_EQ(world->GetEnemyY(), 3) << "Enemy should be at y=3";
    
    // Clear enemy
    world->ClearMainEnemy();
    
    // Verify position is cleared
    EXPECT_FALSE(world->HasEnemy()) << "Enemy should be cleared";
    EXPECT_EQ(world->GetEnemyX(), -1) << "Enemy X should be -1";
    EXPECT_EQ(world->GetEnemyY(), -1) << "Enemy Y should be -1";
}

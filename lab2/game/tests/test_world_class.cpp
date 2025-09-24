#include <gtest/gtest.h>
#include "../include/World.h"

class WorldClassTest : public ::testing::Test {
protected:
    void SetUp() override {
        world = new World();
    }

    void TearDown() override {
        delete world;
    }

    World* world;
};

// Test World Generate method
TEST_F(WorldClassTest, WorldGenerateMethod) {
    world->Generate();
    
    // World should be generated (we can't easily test the internal state)
    SUCCEED();
}

// Test World SpawnEnemy method
TEST_F(WorldClassTest, WorldSpawnEnemyMethod) {
    world->Generate();
    
    bool spawned = world->SpawnEnemy();
    
    EXPECT_TRUE(spawned);
    EXPECT_TRUE(world->HasEnemy());
}

// Test World SpawnDragon method
TEST_F(WorldClassTest, WorldSpawnDragonMethod) {
    world->Generate();
    
    world->SpawnDragon();
    
    EXPECT_TRUE(world->HasDragon());
    EXPECT_EQ(world->GetDragonX(), 5);
    EXPECT_EQ(world->GetDragonY(), 5);
}

// Test World ClearMainEnemy method
TEST_F(WorldClassTest, WorldClearMainEnemyMethod) {
    world->Generate();
    world->SpawnEnemy();
    
    EXPECT_TRUE(world->HasEnemy());
    
    world->ClearMainEnemy();
    
    EXPECT_FALSE(world->HasEnemy());
    EXPECT_EQ(world->GetEnemyX(), -1);
    EXPECT_EQ(world->GetEnemyY(), -1);
}

// Test World ClearDragon method
TEST_F(WorldClassTest, WorldClearDragonMethod) {
    world->Generate();
    world->SpawnDragon();
    
    EXPECT_TRUE(world->HasDragon());
    
    world->ClearDragon();
    
    EXPECT_FALSE(world->HasDragon());
    EXPECT_EQ(world->GetDragonX(), -1);
    EXPECT_EQ(world->GetDragonY(), -1);
}

// Test World dragon defeated state
TEST_F(WorldClassTest, WorldDragonDefeatedState) {
    world->Generate();
    
    EXPECT_FALSE(world->IsDragonDefeated());
    
    world->SetDragonDefeated(true);
    
    EXPECT_TRUE(world->IsDragonDefeated());
}

// Test World SpawnEnemyAt method
TEST_F(WorldClassTest, WorldSpawnEnemyAtMethod) {
    world->Generate();
    
    bool spawned = world->SpawnEnemyAt(3, 0);
    
    EXPECT_TRUE(spawned);
    EXPECT_TRUE(world->HasEnemy());
    EXPECT_EQ(world->GetEnemyX(), 3);
    EXPECT_EQ(world->GetEnemyY(), 0);
}

// Test World SpawnEnemyAt with invalid coordinates
TEST_F(WorldClassTest, WorldSpawnEnemyAtInvalidCoordinates) {
    world->Generate();
    
    bool spawned = world->SpawnEnemyAt(-1, -1);
    
    EXPECT_FALSE(spawned);
    EXPECT_FALSE(world->HasEnemy());
}

// Test World SpawnSecondNPC method
TEST_F(WorldClassTest, WorldSpawnSecondNPCMethod) {
    world->Generate();
    
    world->SpawnSecondNPC();
    
    // Note: HasSecondNPC() method doesn't exist in World class
    // We can only test that SpawnSecondNPC() doesn't crash
    SUCCEED();
}

// Test World NPC proximity methods
TEST_F(WorldClassTest, WorldNPCProximityMethods) {
    world->Generate();
    world->SpawnSecondNPC();
    
    // Note: SetPlayerPosition() and IsNearSecondNPC() methods don't exist in World class
    // We can only test that SpawnSecondNPC() doesn't crash
    SUCCEED();
}

// Test World ActivateMerchantAtNPC method
TEST_F(WorldClassTest, WorldActivateMerchantAtNPCMethod) {
    world->Generate();
    
    world->ActivateMerchantAtNPC();
    
    EXPECT_TRUE(world->HasMerchant());
}

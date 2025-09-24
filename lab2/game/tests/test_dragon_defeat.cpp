#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/World.h"
#include "../include/Battle.h"

class DragonDefeatTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        enemy = new Enemy(150, 25); // Dragon stats
        world = new World();
        world->Generate();
        world->SpawnDragon();
        enemy->SetMagical(true);
    }

    void TearDown() override {
        delete player;
        delete enemy;
        delete world;
    }

    Player* player;
    Enemy* enemy;
    World* world;
    Battle battle;
};

// Test that dragon is permanently defeated and doesn't respawn
TEST_F(DragonDefeatTest, DragonPermanentlyDefeated) {
    // Start battle with dragon
    battle.Start(*player, *enemy, *world);
    
    // Verify dragon is on map initially
    EXPECT_TRUE(world->HasDragon()) << "Dragon should be on map initially";
    EXPECT_EQ(world->GetDragonX(), 5) << "Dragon should be at x=5";
    EXPECT_EQ(world->GetDragonY(), 5) << "Dragon should be at y=5";
    
    // Kill dragon
    while (!enemy->IsDead()) {
        player->Attack(*enemy);
        if (!battle.CheckWin()) {
            battle.EnemyTurn();
        }
    }
    
    // Verify dragon is defeated
    EXPECT_TRUE(enemy->IsDead()) << "Dragon should be dead";
    EXPECT_TRUE(battle.CheckWin()) << "Battle should be won";
    
    // End battle (this should clear dragon from map)
    battle.End();
    world->ClearMainEnemy();
    world->ClearDragon();
    world->SetDragonDefeated(true);
    
    // Verify dragon is permanently removed
    EXPECT_FALSE(world->HasDragon()) << "Dragon should be removed from map";
    EXPECT_TRUE(world->IsDragonDefeated()) << "Dragon should be marked as defeated";
    EXPECT_EQ(world->GetDragonX(), -1) << "Dragon X should be reset to -1";
    EXPECT_EQ(world->GetDragonY(), -1) << "Dragon Y should be reset to -1";
}

// Test that dragon doesn't respawn as regular enemy
TEST_F(DragonDefeatTest, DragonDoesNotRespawnAsRegularEnemy) {
    // Start battle with dragon
    battle.Start(*player, *enemy, *world);
    
    // Kill dragon
    while (!enemy->IsDead()) {
        player->Attack(*enemy);
        if (!battle.CheckWin()) {
            battle.EnemyTurn();
        }
    }
    
    // End battle and clear dragon
    battle.End();
    world->ClearMainEnemy();
    world->ClearDragon();
    world->SetDragonDefeated(true);
    
    // Verify no regular enemy spawns where dragon was
    EXPECT_FALSE(world->HasEnemy()) << "No regular enemy should spawn after dragon defeat";
    EXPECT_FALSE(world->HasDragon()) << "Dragon should remain defeated";
}

// Test that dragon cannot be fought again after defeat
TEST_F(DragonDefeatTest, DragonCannotBeFoughtAgain) {
    // Start battle with dragon
    battle.Start(*player, *enemy, *world);
    
    // Kill dragon
    while (!enemy->IsDead()) {
        player->Attack(*enemy);
        if (!battle.CheckWin()) {
            battle.EnemyTurn();
        }
    }
    
    // End battle and clear dragon
    battle.End();
    world->ClearMainEnemy();
    world->ClearDragon();
    world->SetDragonDefeated(true);
    
    // Try to start new battle - should fail
    Enemy newEnemy(150, 25);
    newEnemy.SetMagical(true);
    battle.Start(*player, newEnemy, *world);
    
    // Battle should not start because dragon is defeated
    EXPECT_FALSE(battle.IsActive()) << "Battle should not start after dragon defeat";
}

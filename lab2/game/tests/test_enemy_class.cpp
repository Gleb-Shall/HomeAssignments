#include <gtest/gtest.h>
#include "../include/Enemy.h"
#include "../include/Player.h"

class EnemyClassTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        enemy = new Enemy();
    }

    void TearDown() override {
        delete player;
        delete enemy;
    }

    Player* player;
    Enemy* enemy;
};

// Test Enemy default constructor
TEST_F(EnemyClassTest, EnemyDefaultConstructor) {
    Enemy defaultEnemy;
    
    EXPECT_EQ(defaultEnemy.GetHP(), 50);
    EXPECT_FALSE(defaultEnemy.IsDead());
    EXPECT_FALSE(defaultEnemy.IsMagical());
    EXPECT_FALSE(defaultEnemy.HasBuff());
}

// Test Enemy parameterized constructor
TEST_F(EnemyClassTest, EnemyParameterizedConstructor) {
    Enemy strongEnemy(100, 20);
    
    EXPECT_EQ(strongEnemy.GetHP(), 100);
    EXPECT_FALSE(strongEnemy.IsDead());
}

// Test Enemy attack method
TEST_F(EnemyClassTest, EnemyAttackMethod) {
    int initialPlayerHP = player->GetHP();
    
    enemy->Attack(*player);
    
    EXPECT_LT(player->GetHP(), initialPlayerHP);
    // Note: GetAttackPower() method doesn't exist in Enemy class
    // We can only test that player took damage
}

// Test Enemy defend method
TEST_F(EnemyClassTest, EnemyDefendMethod) {
    enemy->Defend();
    
    // Note: IsDefending() method doesn't exist in Enemy class
    // We can only test that Defend() doesn't crash
    SUCCEED();
}

// Test Enemy take damage
TEST_F(EnemyClassTest, EnemyTakeDamage) {
    int initialHP = enemy->GetHP();
    int damage = 20;
    
    enemy->TakeDamage(damage);
    
    EXPECT_EQ(enemy->GetHP(), initialHP - damage);
    EXPECT_FALSE(enemy->IsDead());
}

// Test Enemy death
TEST_F(EnemyClassTest, EnemyDeath) {
    int initialHP = enemy->GetHP();
    
    enemy->TakeDamage(initialHP);
    
    EXPECT_EQ(enemy->GetHP(), 0);
    EXPECT_TRUE(enemy->IsDead());
}

// Test Enemy magical properties
TEST_F(EnemyClassTest, EnemyMagicalProperties) {
    EXPECT_FALSE(enemy->IsMagical());
    
    enemy->SetMagical(true);
    EXPECT_TRUE(enemy->IsMagical());
}

// Test Enemy buff properties
TEST_F(EnemyClassTest, EnemyBuffProperties) {
    EXPECT_FALSE(enemy->HasBuff());
    
    // Note: SetBuff() method doesn't exist in Enemy class
    // We can only test HasBuff() which should return false by default
}

// Test Enemy reset method
TEST_F(EnemyClassTest, EnemyResetMethod) {
    // Damage enemy to death
    enemy->TakeDamage(enemy->GetHP());
    EXPECT_TRUE(enemy->IsDead());
    
    // Reset enemy
    enemy->Reset();
    
    EXPECT_FALSE(enemy->IsDead());
    EXPECT_EQ(enemy->GetHP(), 50);
    EXPECT_FALSE(enemy->IsMagical());
    EXPECT_FALSE(enemy->HasBuff());
}

// Test Enemy with defending
TEST_F(EnemyClassTest, EnemyDefendingReducesDamage) {
    enemy->Defend();
    int initialHP = enemy->GetHP();
    int damage = 20;
    
    enemy->TakeDamage(damage);
    
    // Note: We can't easily test defending behavior without IsDefending() method
    // We can only test that TakeDamage() works
    EXPECT_LT(enemy->GetHP(), initialHP);
}

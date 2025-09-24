#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include <iostream>

class DamageTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create fresh player and enemy for each test
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

// Test basic attack damage without weapon
TEST_F(DamageTest, BasicAttackDamage) {
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int finalHP = enemy->GetHP();
    int damageDealt = initialHP - finalHP;
    
    EXPECT_EQ(damageDealt, 15) << "Basic attack should deal 15 damage";
}

// Test attack damage with Iron Sword
TEST_F(DamageTest, IronSwordDamage) {
    // Give player Iron Sword
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int finalHP = enemy->GetHP();
    int damageDealt = initialHP - finalHP;
    
    EXPECT_EQ(damageDealt, 25) << "Iron Sword should deal 15 base + 10 bonus = 25 damage";
}

// Test attack damage with Rusty Dagger
TEST_F(DamageTest, RustyDaggerDamage) {
    // Give player Rusty Dagger
    player->AddItem("Rusty Dagger");
    player->Equip("Rusty Dagger");
    
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int finalHP = enemy->GetHP();
    int damageDealt = initialHP - finalHP;
    
    EXPECT_EQ(damageDealt, 17) << "Rusty Dagger should deal 15 base + 2 bonus = 17 damage";
}

// Test that equipped weapon is correctly set
TEST_F(DamageTest, WeaponEquipping) {
    player->AddItem("Iron Sword");
    bool equipResult = player->Equip("Iron Sword");
    
    EXPECT_TRUE(equipResult) << "Should successfully equip Iron Sword";
    EXPECT_EQ(player->GetEquipped(), "Iron Sword") << "Equipped weapon should be Iron Sword";
}

// Test that unequipped weapon doesn't affect damage
TEST_F(DamageTest, UnequippedWeaponNoBonus) {
    // Give player weapon but don't equip it
    player->AddItem("Iron Sword");
    
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int finalHP = enemy->GetHP();
    int damageDealt = initialHP - finalHP;
    
    EXPECT_EQ(damageDealt, 15) << "Unequipped weapon should not affect damage";
}

// Test multiple attacks with different weapons
TEST_F(DamageTest, MultipleAttacksWithDifferentWeapons) {
    // First attack with no weapon
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int hpAfterFirst = enemy->GetHP();
    int firstDamage = initialHP - hpAfterFirst;
    
    // Equip Iron Sword
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    // Second attack with Iron Sword
    player->Attack(*enemy);
    int hpAfterSecond = enemy->GetHP();
    int secondDamage = hpAfterFirst - hpAfterSecond;
    
    EXPECT_EQ(firstDamage, 15) << "First attack should deal 15 damage";
    EXPECT_EQ(secondDamage, 25) << "Second attack with Iron Sword should deal 25 damage";
}

// Test that enemy takes correct damage
TEST_F(DamageTest, EnemyTakesCorrectDamage) {
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    
    EXPECT_LT(enemy->GetHP(), initialHP) << "Enemy HP should decrease after attack";
    EXPECT_EQ(enemy->GetHP(), initialHP - 15) << "Enemy should take exactly 15 damage";
}

// Test with Iron Sword against multiple enemies
TEST_F(DamageTest, IronSwordAgainstMultipleEnemies) {
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    Enemy enemy1, enemy2;
    int initialHP1 = enemy1.GetHP();
    int initialHP2 = enemy2.GetHP();
    
    player->Attack(enemy1);
    player->Attack(enemy2);
    
    EXPECT_EQ(initialHP1 - enemy1.GetHP(), 25) << "First enemy should take 25 damage";
    EXPECT_EQ(initialHP2 - enemy2.GetHP(), 25) << "Second enemy should take 25 damage";
}

// Test level up increases base damage
TEST_F(DamageTest, LevelUpIncreasesBaseDamage) {
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int damageBeforeLevelUp = initialHP - enemy->GetHP();
    
    // Level up player
    player->LevelUp();
    
    // Create new enemy for fair comparison
    Enemy newEnemy;
    int newInitialHP = newEnemy.GetHP();
    player->Attack(newEnemy);
    int damageAfterLevelUp = newInitialHP - newEnemy.GetHP();
    
    EXPECT_GT(damageAfterLevelUp, damageBeforeLevelUp) << "Damage should increase after level up";
    EXPECT_EQ(damageAfterLevelUp, 17) << "Level up should increase base damage by 2";
}

// Test that weapon bonus is applied correctly
TEST_F(DamageTest, WeaponBonusCalculation) {
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    // Test that the bonus is exactly 10
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int totalDamage = initialHP - enemy->GetHP();
    int weaponBonus = totalDamage - 15; // 15 is base damage
    
    EXPECT_EQ(weaponBonus, 10) << "Iron Sword should provide exactly +10 damage bonus";
}

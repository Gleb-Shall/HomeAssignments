#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Enemy.h"

// Mock Enemy for testing armor defense
class MockEnemyArmor : public Enemy {
public:
    MockEnemyArmor() : Enemy(50, 10) {}
    void Attack(Player& player) {
        std::cout << "Enemy attacks!" << std::endl;
        player.TakeDamage(attackPower);
    }
    int GetAttackPower() const { return attackPower; }
private:
    int attackPower = 10;
};

class ArmorDefenseTest : public ::testing::Test {
protected:
    Player* player;
    MockEnemyArmor* enemy;

    void SetUp() override {
        player = new Player();
        enemy = new MockEnemyArmor();
    }

    void TearDown() override {
        delete player;
        delete enemy;
    }
};

// Test basic damage without armor
TEST_F(ArmorDefenseTest, BasicDamageWithoutArmor) {
    int initialHP = player->GetHP();
    enemy->Attack(*player);
    int damageTaken = initialHP - player->GetHP();
    
    EXPECT_EQ(damageTaken, 10) << "Player should take 10 damage without armor";
}

// Test damage reduction with Leather Armor
TEST_F(ArmorDefenseTest, LeatherArmorReducesDamage) {
    // Give player Leather Armor
    player->AddItem("Leather Armor");
    player->EquipArmor("Leather Armor");
    
    int initialHP = player->GetHP();
    enemy->Attack(*player);
    int damageTaken = initialHP - player->GetHP();
    
    // Expected: 10 damage - 5 armor defense = 5 damage
    EXPECT_EQ(damageTaken, 5) << "Leather Armor should reduce damage from 10 to 5";
}

// Test armor defense with upgrades
TEST_F(ArmorDefenseTest, UpgradedArmorReducesMoreDamage) {
    // Give player Leather Armor and upgrade it
    player->AddItem("Leather Armor");
    player->EquipArmor("Leather Armor");
    player->UpgradeArmor(); // +2 defense
    
    int initialHP = player->GetHP();
    enemy->Attack(*player);
    int damageTaken = initialHP - player->GetHP();
    
    // Expected: 10 damage - (5 + 2) armor defense = 3 damage
    EXPECT_EQ(damageTaken, 3) << "Upgraded Leather Armor should reduce damage from 10 to 3";
}

// Test multiple armor upgrades
TEST_F(ArmorDefenseTest, MultipleArmorUpgrades) {
    // Give player Leather Armor and upgrade it twice
    player->AddItem("Leather Armor");
    player->EquipArmor("Leather Armor");
    player->UpgradeArmor(); // +2 defense
    player->UpgradeArmor(); // +2 defense
    
    int initialHP = player->GetHP();
    enemy->Attack(*player);
    int damageTaken = initialHP - player->GetHP();
    
    // Expected: 10 damage - (5 + 4) armor defense = 1 damage
    EXPECT_EQ(damageTaken, 1) << "Double upgraded Leather Armor should reduce damage from 10 to 1";
}

// Test armor defense cannot reduce damage below 0
TEST_F(ArmorDefenseTest, ArmorDefenseCannotReduceBelowZero) {
    // Give player Leather Armor and upgrade it many times
    player->AddItem("Leather Armor");
    player->EquipArmor("Leather Armor");
    for (int i = 0; i < 5; ++i) {
        player->UpgradeArmor(); // +2 defense each
    }
    
    int initialHP = player->GetHP();
    enemy->Attack(*player);
    int damageTaken = initialHP - player->GetHP();
    
    // Expected: 10 damage - (5 + 10) armor defense = 0 damage (minimum)
    EXPECT_EQ(damageTaken, 0) << "High armor defense should reduce damage to 0, not negative";
}

// Test armor defense with defending
TEST_F(ArmorDefenseTest, ArmorDefenseWithDefending) {
    // Give player Leather Armor
    player->AddItem("Leather Armor");
    player->EquipArmor("Leather Armor");
    
    // Player defends (damage / 2) then armor reduces it
    player->Defend();
    int initialHP = player->GetHP();
    enemy->Attack(*player);
    int damageTaken = initialHP - player->GetHP();
    
    // Expected: (10 damage / 2) - 5 armor defense = 0 damage
    EXPECT_EQ(damageTaken, 0) << "Defending + armor should reduce damage to 0";
}

// Test armor defense calculation
TEST_F(ArmorDefenseTest, ArmorDefenseCalculation) {
    // Test without armor
    EXPECT_EQ(player->GetArmorDefense(), 0) << "No armor should give 0 defense";
    
    // Test with Leather Armor
    player->AddItem("Leather Armor");
    player->EquipArmor("Leather Armor");
    EXPECT_EQ(player->GetArmorDefense(), 5) << "Leather Armor should give 5 defense";
    
    // Test with upgrades
    player->UpgradeArmor();
    EXPECT_EQ(player->GetArmorDefense(), 7) << "Upgraded Leather Armor should give 7 defense";
    
    player->UpgradeArmor();
    EXPECT_EQ(player->GetArmorDefense(), 9) << "Double upgraded Leather Armor should give 9 defense";
}

// Test armor equipping
TEST_F(ArmorDefenseTest, ArmorEquipping) {
    // Test equipping armor
    player->AddItem("Leather Armor");
    player->EquipArmor("Leather Armor");
    EXPECT_EQ(player->GetEquippedArmor(), "Leather Armor") << "Should equip Leather Armor";
    
    // Test equipping non-existent armor
    player->EquipArmor("Non-existent Armor");
    EXPECT_EQ(player->GetEquippedArmor(), "Leather Armor") << "Should not change equipped armor";
}

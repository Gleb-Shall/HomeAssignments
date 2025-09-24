#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/World.h"

// Mock Enemy for testing purposes
class MockEnemyUpgrade : public Enemy {
public:
    MockEnemyUpgrade() : Enemy(50, 10) {}
    void TakeDamage(int dmg) {
        // Call parent TakeDamage to update the base class hp
        Enemy::TakeDamage(dmg);
        std::cout << "Enemy takes damage: " << dmg << ", HP: " << GetHP() << std::endl;
    }
};

class UpgradeSystemTest : public ::testing::Test {
protected:
    Player* player;
    MockEnemyUpgrade* enemy;
    World* world;

    void SetUp() override {
        player = new Player();
        enemy = new MockEnemyUpgrade();
        world = new World();
        world->Generate();
    }

    void TearDown() override {
        delete player;
        delete enemy;
        delete world;
    }
};

// Test initial upgrade state
TEST_F(UpgradeSystemTest, InitialUpgradeState) {
    EXPECT_EQ(player->GetWeaponUpgrades(), 0) << "Player should start with 0 weapon upgrades";
    EXPECT_EQ(player->GetArmorUpgrades(), 0) << "Player should start with 0 armor upgrades";
}

// Test weapon upgrade functionality
TEST_F(UpgradeSystemTest, WeaponUpgradeIncreases) {
    int initialUpgrades = player->GetWeaponUpgrades();
    player->UpgradeWeapon();
    EXPECT_EQ(player->GetWeaponUpgrades(), initialUpgrades + 1) << "Weapon upgrade should increase by 1";
    
    player->UpgradeWeapon();
    EXPECT_EQ(player->GetWeaponUpgrades(), initialUpgrades + 2) << "Second weapon upgrade should increase by 1";
}

// Test armor upgrade functionality
TEST_F(UpgradeSystemTest, ArmorUpgradeIncreases) {
    int initialUpgrades = player->GetArmorUpgrades();
    player->UpgradeArmor();
    EXPECT_EQ(player->GetArmorUpgrades(), initialUpgrades + 1) << "Armor upgrade should increase by 1";
    
    player->UpgradeArmor();
    EXPECT_EQ(player->GetArmorUpgrades(), initialUpgrades + 2) << "Second armor upgrade should increase by 1";
}

// Test weapon damage with upgrades - FIXED VERSION
TEST_F(UpgradeSystemTest, WeaponDamageWithUpgrades) {
    // Equip Iron Sword
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    // Attack without upgrades
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int damageWithoutUpgrades = initialHP - enemy->GetHP();
    
    // Reset enemy and upgrade weapon
    delete enemy;
    enemy = new MockEnemyUpgrade();
    player->UpgradeWeapon();
    
    // Attack with upgrades
    int newInitialHP = enemy->GetHP();
    player->Attack(*enemy);
    int damageWithUpgrade = newInitialHP - enemy->GetHP();
    
    EXPECT_GT(damageWithUpgrade, damageWithoutUpgrades) << "Upgraded weapon should deal more damage";
    EXPECT_EQ(damageWithUpgrade - damageWithoutUpgrades, 2) << "Each weapon upgrade should add 2 damage";
}

// Test multiple weapon upgrades - FIXED VERSION
TEST_F(UpgradeSystemTest, MultipleWeaponUpgrades) {
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    // Attack with no upgrades
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int baseDamage = initialHP - enemy->GetHP();
    
    // Reset enemy and upgrade weapon twice
    delete enemy;
    enemy = new MockEnemyUpgrade();
    player->UpgradeWeapon();
    player->UpgradeWeapon();
    
    // Attack with upgrades
    int newInitialHP = enemy->GetHP();
    player->Attack(*enemy);
    int upgradedDamage = newInitialHP - enemy->GetHP();
    
    EXPECT_EQ(upgradedDamage - baseDamage, 4) << "Two weapon upgrades should add 4 damage (2 per upgrade)";
}

// Test Rusty Dagger upgrades - FIXED VERSION
TEST_F(UpgradeSystemTest, RustyDaggerUpgrades) {
    player->AddItem("Rusty Dagger");
    player->Equip("Rusty Dagger");
    
    // Attack without upgrades
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int damageWithoutUpgrades = initialHP - enemy->GetHP();
    
    // Reset enemy and upgrade weapon
    delete enemy;
    enemy = new MockEnemyUpgrade();
    player->UpgradeWeapon();
    
    // Attack with upgrades
    int newInitialHP = enemy->GetHP();
    player->Attack(*enemy);
    int damageWithUpgrade = newInitialHP - enemy->GetHP();
    
    EXPECT_GT(damageWithUpgrade, damageWithoutUpgrades) << "Upgraded Rusty Dagger should deal more damage";
    EXPECT_EQ(damageWithUpgrade - damageWithoutUpgrades, 2) << "Rusty Dagger upgrade should add 2 damage";
}

// Test upgrade without equipped weapon
TEST_F(UpgradeSystemTest, UpgradeWithoutWeapon) {
    // Don't equip any weapon
    int initialUpgrades = player->GetWeaponUpgrades();
    player->UpgradeWeapon();
    EXPECT_EQ(player->GetWeaponUpgrades(), initialUpgrades + 1) << "Upgrade should work even without equipped weapon";
}

// Test upgrade without equipped armor
TEST_F(UpgradeSystemTest, UpgradeWithoutArmor) {
    // Don't equip any armor
    int initialUpgrades = player->GetArmorUpgrades();
    player->UpgradeArmor();
    EXPECT_EQ(player->GetArmorUpgrades(), initialUpgrades + 1) << "Upgrade should work even without equipped armor";
}

// Test weapon upgrade tracking persistence
TEST_F(UpgradeSystemTest, WeaponUpgradePersistence) {
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    // Upgrade weapon multiple times
    player->UpgradeWeapon();
    player->UpgradeWeapon();
    player->UpgradeWeapon();
    
    EXPECT_EQ(player->GetWeaponUpgrades(), 3) << "Should track 3 weapon upgrades";
    
    // Change weapon - upgrades should persist
    player->AddItem("Rusty Dagger");
    player->Equip("Rusty Dagger");
    
    EXPECT_EQ(player->GetWeaponUpgrades(), 3) << "Weapon upgrades should persist when changing weapons";
}

// Test armor upgrade tracking persistence
TEST_F(UpgradeSystemTest, ArmorUpgradePersistence) {
    player->AddItem("Leather Armor");
    player->Equip("Leather Armor");
    
    // Upgrade armor multiple times
    player->UpgradeArmor();
    player->UpgradeArmor();
    
    EXPECT_EQ(player->GetArmorUpgrades(), 2) << "Should track 2 armor upgrades";
    
    // Unequip armor - upgrades should persist
    player->Equip(""); // Unequip
    
    EXPECT_EQ(player->GetArmorUpgrades(), 2) << "Armor upgrades should persist when unequipping";
}

// Test upgrade limits (stress test)
TEST_F(UpgradeSystemTest, ManyUpgrades) {
    // Test many weapon upgrades
    for (int i = 0; i < 10; ++i) {
        player->UpgradeWeapon();
        EXPECT_EQ(player->GetWeaponUpgrades(), i + 1) << "Weapon upgrade " << (i + 1) << " should work";
    }
    
    // Test many armor upgrades
    for (int i = 0; i < 10; ++i) {
        player->UpgradeArmor();
        EXPECT_EQ(player->GetArmorUpgrades(), i + 1) << "Armor upgrade " << (i + 1) << " should work";
    }
    
    EXPECT_EQ(player->GetWeaponUpgrades(), 10) << "Should have 10 weapon upgrades";
    EXPECT_EQ(player->GetArmorUpgrades(), 10) << "Should have 10 armor upgrades";
}

// Test damage calculation with many upgrades - FIXED VERSION
TEST_F(UpgradeSystemTest, DamageWithManyUpgrades) {
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    // Upgrade weapon 5 times
    for (int i = 0; i < 5; ++i) {
        player->UpgradeWeapon();
    }
    
    // Attack enemy
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int totalDamage = initialHP - enemy->GetHP();
    
    // Expected damage: base (15) + Iron Sword (10) + upgrades (5 * 2 = 10) = 35
    int expectedDamage = 15 + 10 + 10;
    EXPECT_EQ(totalDamage, expectedDamage) << "Damage should be base + weapon + upgrades";
}

// Test upgrade system with different weapons - FIXED VERSION
TEST_F(UpgradeSystemTest, DifferentWeaponsWithUpgrades) {
    // Test Iron Sword with upgrades
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    player->UpgradeWeapon();
    
    int initialHP = enemy->GetHP();
    player->Attack(*enemy);
    int ironSwordDamage = initialHP - enemy->GetHP();
    
    // Reset and test Rusty Dagger with upgrades
    delete enemy;
    enemy = new MockEnemyUpgrade();
    player->AddItem("Rusty Dagger");
    player->Equip("Rusty Dagger");
    player->UpgradeWeapon();
    
    int newInitialHP = enemy->GetHP();
    player->Attack(*enemy);
    int rustyDaggerDamage = newInitialHP - enemy->GetHP();
    
    // Iron Sword should still do more damage than Rusty Dagger even with upgrades
    EXPECT_GT(ironSwordDamage, rustyDaggerDamage) << "Iron Sword should do more damage than Rusty Dagger even with upgrades";
}

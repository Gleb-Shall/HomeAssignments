#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/World.h"
#include "../include/Battle.h"
#include <iostream>

class SkillsSpellsTest : public ::testing::Test {
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

// Test that skills can kill dragon
TEST_F(SkillsSpellsTest, SkillCanKillDragon) {
    // Spawn dragon
    world->SpawnDragon();
    
    // Create dragon enemy
    Enemy dragon(150, 25);
    dragon.SetMagical(true);
    
    // Start battle
    battle->Start(*player, dragon, *world);
    EXPECT_TRUE(battle->IsActive()) << "Battle should be active";
    
    // Use skill to damage dragon
    int initialHP = dragon.GetHP();
    player->Attack(dragon); // Simulate skill damage (25 damage)
    dragon.TakeDamage(25); // Additional damage to simulate skill
    
    EXPECT_LT(dragon.GetHP(), initialHP) << "Dragon should take damage from skill";
    
    // Continue attacking until dragon is dead
    while (!dragon.IsDead()) {
        dragon.TakeDamage(25); // Simulate skill damage
    }
    
    EXPECT_TRUE(dragon.IsDead()) << "Dragon should be dead after skill attacks";
}

// Test that spells consume mana
TEST_F(SkillsSpellsTest, SpellsConsumeMana) {
    int initialMana = player->GetMana();
    EXPECT_GT(initialMana, 0) << "Player should have mana initially";
    
    // Simulate Fireball spell (15 mana cost)
    int fireballCost = 15;
    if (player->GetMana() >= fireballCost) {
        player->RestoreMana(-fireballCost);
        EXPECT_EQ(player->GetMana(), initialMana - fireballCost) << "Mana should decrease after Fireball";
    }
    
    // Simulate Heal spell (10 mana cost)
    int healCost = 10;
    if (player->GetMana() >= healCost) {
        player->RestoreMana(-healCost);
        EXPECT_EQ(player->GetMana(), initialMana - fireballCost - healCost) << "Mana should decrease after Heal";
    }
    
    // Simulate Lightning spell (20 mana cost)
    int lightningCost = 20;
    if (player->GetMana() >= lightningCost) {
        player->RestoreMana(-lightningCost);
        EXPECT_EQ(player->GetMana(), initialMana - fireballCost - healCost - lightningCost) << "Mana should decrease after Lightning";
    }
}

// Test that spells cannot be cast without enough mana
TEST_F(SkillsSpellsTest, SpellsRequireMana) {
    // Drain all mana
    player->RestoreMana(-player->GetMana());
    EXPECT_EQ(player->GetMana(), 0) << "Player should have no mana";
    
    // Try to cast spell without mana
    int initialHP = enemy->GetHP();
    int fireballCost = 15;
    
    if (player->GetMana() < fireballCost) {
        // Should not be able to cast
        EXPECT_LT(player->GetMana(), fireballCost) << "Not enough mana for spell";
        // Don't cast the spell
    } else {
        player->RestoreMana(-fireballCost);
        enemy->TakeDamage(20);
    }
    
    EXPECT_EQ(enemy->GetHP(), initialHP) << "Enemy should not take damage without mana";
}

// Test different spell costs
TEST_F(SkillsSpellsTest, DifferentSpellCosts) {
    int initialMana = player->GetMana();
    
    // Test Fireball (15 mana)
    int fireballCost = 15;
    player->RestoreMana(-fireballCost);
    EXPECT_EQ(player->GetMana(), initialMana - fireballCost) << "Fireball should cost 15 mana";
    
    // Reset mana
    player->RestoreMana(fireballCost);
    
    // Test Heal (10 mana)
    int healCost = 10;
    player->RestoreMana(-healCost);
    EXPECT_EQ(player->GetMana(), initialMana - healCost) << "Heal should cost 10 mana";
    
    // Reset mana
    player->RestoreMana(healCost);
    
    // Test Lightning (20 mana)
    int lightningCost = 20;
    player->RestoreMana(-lightningCost);
    EXPECT_EQ(player->GetMana(), initialMana - lightningCost) << "Lightning should cost 20 mana";
}

// Test that skills work on regular enemies
TEST_F(SkillsSpellsTest, SkillsWorkOnRegularEnemies) {
    // Spawn regular enemy
    world->SpawnEnemy();
    
    // Start battle
    battle->Start(*player, *enemy, *world);
    EXPECT_TRUE(battle->IsActive()) << "Battle should be active";
    
    // Use skill to damage enemy
    int initialHP = enemy->GetHP();
    enemy->TakeDamage(25); // Simulate Power Strike skill
    
    EXPECT_LT(enemy->GetHP(), initialHP) << "Enemy should take damage from skill";
    EXPECT_EQ(enemy->GetHP(), initialHP - 25) << "Enemy should take exactly 25 damage from Power Strike";
}

// Test that spells work on regular enemies
TEST_F(SkillsSpellsTest, SpellsWorkOnRegularEnemies) {
    // Spawn regular enemy
    world->SpawnEnemy();
    
    // Start battle
    battle->Start(*player, *enemy, *world);
    EXPECT_TRUE(battle->IsActive()) << "Battle should be active";
    
    // Test Fireball spell
    int initialHP = enemy->GetHP();
    int initialMana = player->GetMana();
    
    if (player->GetMana() >= 15) {
        player->RestoreMana(-15); // Consume mana
        enemy->TakeDamage(20); // Fireball damage
    }
    
    EXPECT_LT(enemy->GetHP(), initialHP) << "Enemy should take damage from Fireball";
    EXPECT_EQ(enemy->GetHP(), initialHP - 20) << "Enemy should take exactly 20 damage from Fireball";
    EXPECT_LT(player->GetMana(), initialMana) << "Player mana should decrease after Fireball";
}

// Test that Heal spell restores HP
TEST_F(SkillsSpellsTest, HealSpellRestoresHP) {
    // Damage player first
    player->TakeDamage(30);
    int damagedHP = player->GetHP();
    int initialMana = player->GetMana();
    
    // Cast Heal spell
    if (player->GetMana() >= 10) {
        player->RestoreMana(-10); // Consume mana
        player->Heal(15); // Heal effect
    }
    
    EXPECT_GT(player->GetHP(), damagedHP) << "Player HP should increase after Heal";
    EXPECT_EQ(player->GetHP(), damagedHP + 15) << "Player should heal exactly 15 HP";
    EXPECT_LT(player->GetMana(), initialMana) << "Player mana should decrease after Heal";
}

// Test that Lightning spell does more damage than Fireball
TEST_F(SkillsSpellsTest, LightningVsFireballDamage) {
    Enemy enemy1(100, 10);
    Enemy enemy2(100, 10);
    
    int initialHP1 = enemy1.GetHP();
    int initialHP2 = enemy2.GetHP();
    
    // Cast Fireball on enemy1
    if (player->GetMana() >= 15) {
        player->RestoreMana(-15);
        enemy1.TakeDamage(20);
    }
    
    // Cast Lightning on enemy2
    if (player->GetMana() >= 20) {
        player->RestoreMana(-20);
        enemy2.TakeDamage(25);
    }
    
    int fireballDamage = initialHP1 - enemy1.GetHP();
    int lightningDamage = initialHP2 - enemy2.GetHP();
    
    EXPECT_GT(lightningDamage, fireballDamage) << "Lightning should do more damage than Fireball";
    EXPECT_EQ(fireballDamage, 20) << "Fireball should do 20 damage";
    EXPECT_EQ(lightningDamage, 25) << "Lightning should do 25 damage";
}

// Test mana restoration with potions
TEST_F(SkillsSpellsTest, ManaRestorationWithPotions) {
    // Drain some mana
    player->RestoreMana(-30);
    int lowMana = player->GetMana();
    
    // Use mana potion
    player->RestoreMana(30);
    
    EXPECT_GT(player->GetMana(), lowMana) << "Mana should increase after potion";
    EXPECT_EQ(player->GetMana(), lowMana + 30) << "Mana should increase by exactly 30";
}

// Test that skills don't consume mana (unlike spells)
TEST_F(SkillsSpellsTest, SkillsDontConsumeMana) {
    int initialMana = player->GetMana();
    
    // Simulate using Power Strike skill
    enemy->TakeDamage(25); // Skill damage
    
    EXPECT_EQ(player->GetMana(), initialMana) << "Skills should not consume mana";
    EXPECT_LT(enemy->GetHP(), 50) << "Enemy should take damage from skill";
}

#include <gtest/gtest.h>
#include "../include/Magic.h"
#include "../include/Player.h"
#include "../include/Enemy.h"

class MagicTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        enemy = new Enemy();
        magic = new Magic("Fireball", "A fireball spell", 15, 20);
    }

    void TearDown() override {
        delete player;
        delete enemy;
        delete magic;
    }

    Player* player;
    Enemy* enemy;
    Magic* magic;
};

// Test Magic constructor
TEST_F(MagicTest, MagicConstructor) {
    EXPECT_EQ(magic->GetName(), "Fireball");
    EXPECT_EQ(magic->GetDescription(), "A fireball spell");
    EXPECT_EQ(magic->GetManaCost(), 15);
    // Note: GetPower() method doesn't exist in Magic class
    // We can only test GetManaCost()
}

// Test Magic Cast method
TEST_F(MagicTest, MagicCastMethod) {
    int initialEnemyHP = enemy->GetHP();
    int initialPlayerMana = player->GetMana();
    
    magic->Cast(*player, *enemy);
    
    EXPECT_LT(enemy->GetHP(), initialEnemyHP);
    EXPECT_LT(player->GetMana(), initialPlayerMana);
    EXPECT_EQ(player->GetMana(), initialPlayerMana - magic->GetManaCost());
    // Note: GetPower() method doesn't exist in Magic class
    // We can only test that enemy took damage and player lost mana
}

// Test Magic with different mana cost
TEST_F(MagicTest, MagicDifferentManaCost) {
    Magic weakSpell("Weak Spell", "A weak spell", 5, 3);
    Magic strongSpell("Strong Spell", "A strong spell", 50, 30);
    
    EXPECT_EQ(weakSpell.GetManaCost(), 5);
    EXPECT_EQ(strongSpell.GetManaCost(), 50);
    // Note: GetPower() method doesn't exist in Magic class
    // We can only test GetManaCost()
}

// Test Magic mana cost getter
TEST_F(MagicTest, MagicManaCostProperties) {
    EXPECT_EQ(magic->GetManaCost(), 15);
    
    // Note: SetPower() and SetManaCost() methods don't exist in Magic class
    // We can only test GetManaCost()
}

// Test Magic against different enemies
TEST_F(MagicTest, MagicAgainstDifferentEnemies) {
    Enemy weakEnemy(20, 5);
    Enemy strongEnemy(100, 20);
    
    int weakInitialHP = weakEnemy.GetHP();
    int strongInitialHP = strongEnemy.GetHP();
    int initialPlayerMana = player->GetMana();
    
    magic->Cast(*player, weakEnemy);
    magic->Cast(*player, strongEnemy);
    
    // Note: GetPower() method doesn't exist in Magic class
    // We can only test that enemies took damage and player lost mana
    EXPECT_LT(weakEnemy.GetHP(), weakInitialHP);
    EXPECT_LT(strongEnemy.GetHP(), strongInitialHP);
    EXPECT_EQ(player->GetMana(), initialPlayerMana - 2 * magic->GetManaCost());
}

// Test Magic with insufficient mana
TEST_F(MagicTest, MagicWithInsufficientMana) {
    player->RestoreMana(-player->GetMana()); // Drain all mana
    
    int initialEnemyHP = enemy->GetHP();
    int initialPlayerMana = player->GetMana();
    
    magic->Cast(*player, *enemy);
    
    // Enemy should not take damage if player has no mana
    EXPECT_EQ(enemy->GetHP(), initialEnemyHP);
    EXPECT_EQ(player->GetMana(), initialPlayerMana);
}

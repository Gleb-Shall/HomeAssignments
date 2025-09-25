#include "Enemy.h"
#include "Player.h"
#include "Utils.h"
#include <iostream>

Enemy::Enemy() : hp(50), attackPower(10), defending(false), isMagical(false), hasBuff(false) {}

Enemy::Enemy(int health, int attack) : hp(health), attackPower(attack), defending(false), isMagical(false), hasBuff(false) {}

void Enemy::Attack(Player& player) {
    std::cout << "Enemy attacks!" << std::endl;
    player.TakeDamage(attackPower);
}

void Enemy::Defend() {
    defending = true;
    std::cout << "Enemy defends!" << std::endl;
}

void Enemy::Think(Player& player) {
    // AI according to technical specification
    int playerHP = player.GetHP();
    int playerMaxHP = player.GetMaxHp();
    int enemyHP = GetHP();
    int enemyMaxHP = 50; // base enemy HP
    
    // 1. If HP < 20% → 50% chance to use potion or run away
    if (enemyHP < enemyMaxHP * 0.2) {
        int choice = Utils::RandomInt(1, 100);
        if (choice <= 50) {
            // Try to run away or use potion
            std::cout << "Enemy tries to run away or use potion!" << std::endl;
            return;
        }
    }
    
    // 2. If player is defending → enemy more likely to use magic or special skill
    if (player.IsDefending()) {
        int choice = Utils::RandomInt(1, 100);
        if (choice <= 70) {
            // Use magic or special skill
            std::cout << "Enemy uses magic against defending player!" << std::endl;
            return;
        }
    }
    
    // 3. If enemy has buff → attacks stronger
    if (HasBuff()) {
        std::cout << "Buffed enemy attacks stronger!" << std::endl;
        attackPower += 5;
    }
    
    // 4. If player is weak (HP < 30%) → enemy finishes with attack
    if (playerHP < playerMaxHP * 0.3) {
        std::cout << "Enemy sees weakness and attacks!" << std::endl;
        attackPower += 3;
    }
    
    // 5. If enemy is magical → casts spells more often, if physical → attacks directly more often
    if (isMagical) {
        int choice = Utils::RandomInt(1, 100);
        if (choice <= 60) {
            std::cout << "Magical enemy casts spell!" << std::endl;
            return;
        }
    }
}

void Enemy::TakeDamage(int dmg) {
    int actual = defending ? dmg / 2 : dmg;
    hp -= actual;
    if (hp < 0) hp = 0;
    std::cout << "Enemy takes damage: " << actual << ", HP: " << hp << std::endl;
    defending = false;
}

void Enemy::DropLoot() {
    std::cout << "Enemy dropped loot (placeholder)." << std::endl;
}

int Enemy::GetHP() const { return hp; }

bool Enemy::HasBuff() const { return hasBuff; }

void Enemy::Reset() {
    hp = 50; // Reset to default HP
    attackPower = 10; // Reset to default attack
    defending = false;
    isMagical = false;
    hasBuff = false;
}

/**
 * @file Player.cpp
 * @brief Implementation of the player character class
 * @author Gleb Shikunov
 */

#include "Player.h"
#include "Enemy.h"
#include <iostream>

/**
 * @brief Default constructor
 * 
 * Initializes player with default stats and empty inventory.
 */
Player::Player() : hp(100), maxHp(100), mana(50), maxMana(50), level(1), attackPower(15), defending(false), gold(100), equipped(""), equippedArmor(""), equippedArtifact(""), weaponUpgrades(0), armorUpgrades(0) {}

/**
 * @brief Attack an enemy
 * @param enemy Reference to the enemy to attack
 * 
 * Performs an attack against the specified enemy, dealing damage
 * based on player's attack power and weapon.
 */
void Player::Attack(Enemy& enemy) {
    std::cout << "Player attacks!" << std::endl;
    // Calculate damage including weapon bonus and upgrades
    int totalDamage = attackPower;
    if (equipped == "Iron Sword") {
        totalDamage += 10; // Iron Sword adds 10 damage
        totalDamage += weaponUpgrades * 2; // Each upgrade adds 2 damage
        std::cout << "Iron Sword bonus: +" << (10 + weaponUpgrades * 2) << " damage!" << std::endl;
    } else if (equipped == "Rusty Dagger") {
        totalDamage += 2; // Rusty Dagger adds 2 damage
        totalDamage += weaponUpgrades * 2; // Each upgrade adds 2 damage
        std::cout << "Rusty Dagger bonus: +" << (2 + weaponUpgrades * 2) << " damage!" << std::endl;
    }
    enemy.TakeDamage(totalDamage);
}

void Player::Defend() {
    defending = true;
    std::cout << "Player defends!" << std::endl;
}

void Player::UseItem(Item&) {
    std::cout << "Player uses item (placeholder)." << std::endl;
}

void Player::Move(int, int) {
    std::cout << "Player moves (placeholder)." << std::endl;
}

void Player::LevelUp() {
    level++;
    maxHp += 10;
    hp = maxHp; // Full heal on level up
    attackPower += 2;
    maxMana += 5;
    mana = maxMana; // Full mana on level up
    std::cout << "Level up! Now level: " << level << std::endl;
    std::cout << "HP increased to: " << maxHp << ", Attack: " << attackPower << ", Mana: " << maxMana << std::endl;
}

void Player::TakeDamage(int dmg) {
    int actual = defending ? dmg / 2 : dmg;
    
    // Apply armor defense
    int armorDefense = GetArmorDefense();
    if (armorDefense > 0) {
        actual -= armorDefense;
        if (actual < 0) actual = 0;
        std::cout << "Armor reduces damage by " << armorDefense << "!" << std::endl;
    }
    
    hp -= actual;
    if (hp < 0) hp = 0;
    std::cout << "Player takes damage: " << actual << ", HP: " << hp << std::endl;
    defending = false;
}

int Player::GetHP() const { return hp; }

bool Player::IsDefending() const { return defending; }

void Player::Heal(int amount) {
    hp += amount;
    if (hp > maxHp) hp = maxHp;
    std::cout << "Player heals: +" << amount << ", HP: " << hp << std::endl;
}

void Player::AddGold(int amount) {
    gold += amount;
    std::cout << "You received gold: +" << amount << ", total gold: " << gold << std::endl;
}

int Player::GetGold() const { return gold; }

void Player::AddItem(const std::string& name) {
    inventory.push_back(name);
    std::cout << "Item received: " << name << std::endl;
}

const std::vector<std::string>& Player::GetInventory() const { return inventory; }

bool Player::Equip(const std::string& name) {
    // Simple logic: can equip any item by name if it's in inventory
    for (const auto& it : inventory) {
        if (it == name) { equipped = name; std::cout << "You equipped: " << name << std::endl; return true; }
    }
    std::cout << "Item not found in inventory: " << name << std::endl;
    return false;
}

std::string Player::GetEquipped() const { return equipped; }

bool Player::HasItem(const std::string& name) const {
    for (const auto& it : inventory) if (it == name) return true; return false;
}

bool Player::RemoveItemByName(const std::string& name) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (*it == name) { inventory.erase(it); return true; }
    }
    return false;
}

void Player::RestoreMana(int amount) {
    mana += amount;
    if (mana > maxMana) mana = maxMana;
    std::cout << "Mana restored: +" << amount << ", Mana: " << mana << "/" << maxMana << std::endl;
}

void Player::AddBuff(const std::string& buffName, int power, int duration) {
    // Remove existing buff with same name
    RemoveBuff(buffName);
    buffs.push_back({buffName, power, duration});
    std::cout << "Buff received: " << buffName << " (power: " << power << ", duration: " << duration << ")" << std::endl;
}

void Player::RemoveBuff(const std::string& buffName) {
    for (auto it = buffs.begin(); it != buffs.end(); ++it) {
        if (it->name == buffName) {
            buffs.erase(it);
            break;
        }
    }
}

bool Player::HasBuff(const std::string& buffName) const {
    for (const auto& buff : buffs) {
        if (buff.name == buffName) return true;
    }
    return false;
}

int Player::GetBuffPower(const std::string& buffName) const {
    for (const auto& buff : buffs) {
        if (buff.name == buffName) return buff.power;
    }
    return 0;
}

void Player::UpgradeWeapon() {
    weaponUpgrades++;
    std::cout << "Weapon upgraded! Total upgrades: " << weaponUpgrades << std::endl;
}

void Player::UpgradeArmor() {
    armorUpgrades++;
    std::cout << "Armor upgraded! Total upgrades: " << armorUpgrades << std::endl;
}

void Player::EquipArmor(const std::string& name) {
    if (HasItem(name)) {
        equippedArmor = name;
        std::cout << "You equipped armor: " << name << std::endl;
    } else {
        std::cout << "You don't have " << name << " in your inventory!" << std::endl;
    }
}

int Player::GetArmorDefense() const {
    if (equippedArmor == "Leather Armor") {
        return 5 + armorUpgrades * 2; // Base defense + upgrades
    }
    return 0;
}

void Player::EquipArtifact(const std::string& name) {
    if (HasItem(name)) {
        equippedArtifact = name;
        std::cout << "You equipped artifact: " << name << std::endl;
    } else {
        std::cout << "You don't have " << name << " in your inventory!" << std::endl;
    }
}

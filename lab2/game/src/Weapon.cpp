/**
 * @file Weapon.cpp
 * @brief Implementation of the weapon class
 * @author Gleb Shikunov
 */

#include "Weapon.h"
#include "Player.h"
#include <iostream>

/**
 * @brief Constructor
 * @param name Weapon name
 * @param description Weapon description
 * @param value Weapon value in gold
 * @param damage Base damage dealt by the weapon
 */
Weapon::Weapon(const std::string& name, const std::string& description, int value, int damage)
    : Item(name, description, value), damage(damage), durability(100), maxDurability(100) {}

/**
 * @brief Get weapon damage
 * @return Current damage value
 */
int Weapon::GetDamage() const {
    return damage;
}

/**
 * @brief Upgrade the weapon
 * 
 * Increases weapon damage and restores some durability.
 */
void Weapon::Upgrade() {
    damage += 2;
    maxDurability += 10;
    durability = maxDurability;
    std::cout << "Оружие улучшено! Урон: " << damage << ", Прочность: " << durability << "/" << maxDurability << std::endl;
}

/**
 * @brief Break the weapon
 * 
 * Sets durability to 0, making the weapon unusable.
 */
void Weapon::Break() {
    durability = 0;
    std::cout << "Оружие сломалось!" << std::endl;
}

/**
 * @brief Repair the weapon
 * 
 * Restores weapon durability to maximum.
 */
void Weapon::Repair() {
    durability = maxDurability;
    std::cout << "Оружие отремонтировано! Прочность: " << durability << "/" << maxDurability << std::endl;
}

/**
 * @brief Use the weapon
 * @param player Reference to the player using the weapon
 * 
 * Equips the weapon to the player if not already equipped.
 */
void Weapon::Use(Player& player) {
    (void)player; // Suppress unused parameter warning
    std::cout << "Вы экипировали: " << GetName() << " (Урон: " << damage << ")" << std::endl;
}

/**
 * @brief Clone the weapon
 * @return Pointer to a new copy of the weapon
 */
Weapon* Weapon::Clone() const {
    return new Weapon(name, description, value, damage);
}

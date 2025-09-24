#include "Weapon.h"
#include "Player.h"
#include <iostream>

Weapon::Weapon(const std::string& name, const std::string& description, int value, int damage)
    : Item(name, description, value), damage(damage), durability(100), maxDurability(100) {}

int Weapon::GetDamage() const {
    return damage;
}

void Weapon::Upgrade() {
    damage += 2;
    maxDurability += 10;
    durability = maxDurability;
    std::cout << "Оружие улучшено! Урон: " << damage << ", Прочность: " << durability << "/" << maxDurability << std::endl;
}

void Weapon::Break() {
    durability = 0;
    std::cout << "Оружие сломалось!" << std::endl;
}

void Weapon::Repair() {
    durability = maxDurability;
    std::cout << "Оружие отремонтировано! Прочность: " << durability << "/" << maxDurability << std::endl;
}

void Weapon::Use(Player& player) {
    (void)player; // Suppress unused parameter warning
    std::cout << "Вы экипировали: " << GetName() << " (Урон: " << damage << ")" << std::endl;
}

Weapon* Weapon::Clone() const {
    return new Weapon(name, description, value, damage);
}

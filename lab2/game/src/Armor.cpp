#include "Armor.h"
#include "Player.h"
#include <iostream>

Armor::Armor(const std::string& name, const std::string& description, int value, int defense)
    : Item(name, description, value), defense(defense), durability(100), maxDurability(100) {}

int Armor::GetDefense() const {
    return defense;
}

void Armor::Upgrade() {
    defense += 2;
    maxDurability += 10;
    durability = maxDurability;
    std::cout << "Броня улучшена! Защита: " << defense << ", Прочность: " << durability << "/" << maxDurability << std::endl;
}

void Armor::Break() {
    durability = 0;
    std::cout << "Броня сломалась!" << std::endl;
}

void Armor::Repair() {
    durability = maxDurability;
    std::cout << "Броня отремонтирована! Прочность: " << durability << "/" << maxDurability << std::endl;
}

void Armor::Use(Player& player) {
    (void)player; // Suppress unused parameter warning
    std::cout << "Вы экипировали: " << GetName() << " (Защита: " << defense << ")" << std::endl;
}

Armor* Armor::Clone() const {
    return new Armor(name, description, value, defense);
}

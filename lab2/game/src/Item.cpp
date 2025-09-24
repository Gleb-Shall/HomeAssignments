#include "Item.h"
#include "Player.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& description, int value) 
    : name(name), description(description), value(value) {}

void Item::Use(Player& player) {
    (void)player; // Suppress unused parameter warning
    std::cout << "Используется предмет: " << name << std::endl;
}

std::string Item::GetName() const {
    return name;
}

std::string Item::GetDescription() const {
    return description;
}

int Item::GetValue() const {
    return value;
}

Item* Item::Clone() const {
    return new Item(name, description, value);
}

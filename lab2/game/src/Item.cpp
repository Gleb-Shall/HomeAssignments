/**
 * @file Item.cpp
 * @brief Implementation of the base item class
 * @author Gleb Shikunov
 */

#include "Item.h"
#include "Player.h"
#include <iostream>

/**
 * @brief Constructor
 * @param name Item name
 * @param description Item description
 * @param value Item value in gold
 */
Item::Item(const std::string& name, const std::string& description, int value) 
    : name(name), description(description), value(value) {}

/**
 * @brief Use the item
 * @param player Reference to the player using the item
 * 
 * Pure virtual method that must be implemented by derived classes
 * to define specific item behavior when used.
 */
void Item::Use(Player& player) {
    (void)player; // Suppress unused parameter warning
    std::cout << "Используется предмет: " << name << std::endl;
}

/**
 * @brief Get item name
 * @return Item name
 */
std::string Item::GetName() const {
    return name;
}

/**
 * @brief Get item description
 * @return Item description
 */
std::string Item::GetDescription() const {
    return description;
}

/**
 * @brief Get item value
 * @return Item value in gold
 */
int Item::GetValue() const {
    return value;
}

/**
 * @brief Clone the item
 * @return Pointer to a new copy of the item
 * 
 * Creates a deep copy of the item. Must be implemented by derived classes.
 */
Item* Item::Clone() const {
    return new Item(name, description, value);
}

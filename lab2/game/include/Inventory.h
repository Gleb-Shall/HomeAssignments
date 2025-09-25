/**
 * @file Inventory.h
 * @brief Player inventory management class
 * @author Gleb Shikunov
 */

#pragma once
#include "Item.h"
#include <vector>
#include <string>

/**
 * @class Inventory
 * @brief Manages player's item collection
 * 
 * This class handles the storage and management of player items,
 * including adding, removing, finding, and using items.
 */
class Inventory {
public:
    /**
     * @brief Destructor
     * 
     * Cleans up all items in the inventory.
     */
    ~Inventory();
    
    /**
     * @brief Add item to inventory
     * @param item Item to add
     * 
     * Adds a new item to the player's inventory.
     */
    void Add(Item& item);
    
    /**
     * @brief Remove item from inventory
     * @param item Item to remove
     * 
     * Removes the specified item from the inventory.
     */
    void Remove(Item& item);
    
    /**
     * @brief Find item by name
     * @param name Name of the item to find
     * @return Pointer to the item, or nullptr if not found
     */
    Item* Find(std::string name);
    
    /**
     * @brief List all items
     * 
     * Displays all items currently in the inventory.
     */
    void List();
    
    /**
     * @brief Use an item
     * @param name Name of the item to use
     * 
     * Uses the specified item and applies its effects.
     */
    void UseItem(std::string name);
    
    /**
     * @brief Get all items
     * @return Reference to the items vector
     */
    const std::vector<Item*>& GetItems() const { return items; }

private:
    std::vector<Item*> items;   ///< Collection of items in inventory
};

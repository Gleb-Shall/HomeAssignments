/**
 * @file Shop.h
 * @brief Shop trading system class
 * @author Gleb Shikunov
 */

#pragma once
#include "Player.h"
#include "Item.h"
#include <vector>

/**
 * @class Shop
 * @brief Manages item trading between player and shop
 * 
 * This class handles buying and selling items, managing shop inventory,
 * and processing transactions with the player.
 */
class Shop {
public:
    /**
     * @brief Destructor
     * 
     * Cleans up all items in the shop inventory.
     */
    ~Shop();
    
    /**
     * @brief Buy an item
     * @param p Reference to the player buying the item
     * @param i Reference to the item being bought
     * 
     * Processes item purchase, deducting gold from player and adding item to inventory.
     */
    void Buy(Player& p, Item& i);
    
    /**
     * @brief Sell an item
     * @param p Reference to the player selling the item
     * @param i Reference to the item being sold
     * 
     * Processes item sale, adding gold to player and removing item from inventory.
     */
    void Sell(Player& p, Item& i);
    
    /**
     * @brief List available goods
     * 
     * Displays all items available for purchase in the shop.
     */
    void ListGoods();
    
    /**
     * @brief Add item to shop
     * @param i Item to add to shop inventory
     * 
     * Adds a new item to the shop's available goods.
     */
    void AddItem(Item& i);
    
    /**
     * @brief Remove item from shop
     * @param i Item to remove from shop inventory
     * 
     * Removes an item from the shop's available goods.
     */
    void RemoveItem(Item& i);
    
    /**
     * @brief Get shop goods
     * @return Reference to the goods vector
     */
    const std::vector<Item*>& GetGoods() const { return goods; }

private:
    std::vector<Item*> goods;   ///< Collection of items available in shop
};

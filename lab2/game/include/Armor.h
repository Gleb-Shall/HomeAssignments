/**
 * @file Armor.h
 * @brief Armor item class
 * @author Gleb Shikunov
 */

#pragma once
#include "Item.h"
#include "Player.h"

/**
 * @class Armor
 * @brief Armor item that provides defense in combat
 * 
 * Inherits from Item and adds armor-specific functionality including
 * defense value, durability management, and upgrade capabilities.
 */
class Armor : public Item {
public:
    /**
     * @brief Constructor
     * @param name Armor name
     * @param description Armor description
     * @param value Armor value in gold
     * @param defense Defense value provided by the armor
     */
    Armor(const std::string& name = "", const std::string& description = "", int value = 0, int defense = 0);
    
    /**
     * @brief Get armor defense
     * @return Current defense value
     */
    int GetDefense() const;
    
    /**
     * @brief Upgrade the armor
     * 
     * Increases armor defense and restores some durability.
     */
    void Upgrade();
    
    /**
     * @brief Break the armor
     * 
     * Sets durability to 0, making the armor unusable.
     */
    void Break();
    
    /**
     * @brief Repair the armor
     * 
     * Restores armor durability to maximum.
     */
    void Repair();
    
    /**
     * @brief Use the armor
     * @param p Reference to the player using the armor
     * 
     * Equips the armor to the player if not already equipped.
     */
    void Use(Player& p) override;
    
    /**
     * @brief Clone the armor
     * @return Pointer to a new copy of the armor
     */
    Armor* Clone() const override;
    
    /**
     * @brief Get current durability
     * @return Current durability value
     */
    int GetDurability() const { return durability; }
    
    /**
     * @brief Get maximum durability
     * @return Maximum durability value
     */
    int GetMaxDurability() const { return maxDurability; }

private:
    int defense;            ///< Defense value provided by the armor
    int durability;         ///< Current durability
    int maxDurability;      ///< Maximum durability
};

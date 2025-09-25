/**
 * @file Weapon.h
 * @brief Weapon item class
 * @author Gleb Shikunov
 */

#pragma once
#include "Item.h"
#include "Player.h"

/**
 * @class Weapon
 * @brief Weapon item that can be equipped and used in combat
 * 
 * Inherits from Item and adds weapon-specific functionality including
 * damage dealing, durability management, and upgrade capabilities.
 */
class Weapon : public Item {
public:
    /**
     * @brief Constructor
     * @param name Weapon name
     * @param description Weapon description
     * @param value Weapon value in gold
     * @param damage Base damage dealt by the weapon
     */
    Weapon(const std::string& name = "", const std::string& description = "", int value = 0, int damage = 0);
    
    /**
     * @brief Get weapon damage
     * @return Current damage value
     */
    int GetDamage() const;
    
    /**
     * @brief Upgrade the weapon
     * 
     * Increases weapon damage and restores some durability.
     */
    void Upgrade();
    
    /**
     * @brief Break the weapon
     * 
     * Sets durability to 0, making the weapon unusable.
     */
    void Break();
    
    /**
     * @brief Repair the weapon
     * 
     * Restores weapon durability to maximum.
     */
    void Repair();
    
    /**
     * @brief Use the weapon
     * @param p Reference to the player using the weapon
     * 
     * Equips the weapon to the player if not already equipped.
     */
    void Use(Player& p) override;
    
    /**
     * @brief Clone the weapon
     * @return Pointer to a new copy of the weapon
     */
    Weapon* Clone() const override;
    
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
    int damage;             ///< Base damage dealt by the weapon
    int durability;         ///< Current durability
    int maxDurability;      ///< Maximum durability
};

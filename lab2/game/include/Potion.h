/**
 * @file Potion.h
 * @brief Potion item class
 * @author Gleb Shikunov
 */

#pragma once
#include "Item.h"
#include "Player.h"
#include <string>

/**
 * @class Potion
 * @brief Consumable potion item with various effects
 * 
 * Inherits from Item and adds potion-specific functionality including
 * effect application, power level, and expiration status.
 */
class Potion : public Item {
public:
    /**
     * @brief Constructor
     * @param name Potion name
     * @param description Potion description
     * @param value Potion value in gold
     * @param effect Type of effect the potion provides
     * @param power Power level of the effect
     */
    Potion(const std::string& name = "", const std::string& description = "", int value = 0, 
           const std::string& effect = "", int power = 0);
    
    /**
     * @brief Drink the potion
     * @param p Reference to the player drinking the potion
     * 
     * Applies the potion's effect to the player and marks it as consumed.
     */
    void Drink(Player& p);
    
    /**
     * @brief Get potion effect type
     * @return Type of effect the potion provides
     */
    std::string GetEffect() const;
    
    /**
     * @brief Check if potion is expired
     * @return True if potion has been consumed
     */
    bool IsExpired() const;
    
    /**
     * @brief Use the potion
     * @param p Reference to the player using the potion
     * 
     * Calls Drink() method to apply the potion's effect.
     */
    void Use(Player& p) override;
    
    /**
     * @brief Clone the potion
     * @return Pointer to a new copy of the potion
     */
    Potion* Clone() const override;

private:
    std::string effect;     ///< Type of effect the potion provides
    int power;              ///< Power level of the effect
    bool expired;           ///< Whether the potion has been consumed
};

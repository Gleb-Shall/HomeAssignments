/**
 * @file Magic.h
 * @brief Magic spells class
 * @author Gleb Shikunov
 */

#pragma once
#include "Skill.h"
#include "Item.h"

/**
 * @class Magic
 * @brief Magic spells that inherit from Skill
 * 
 * This class represents magical abilities that require mana to cast
 * and can have various effects on players, enemies, and items.
 */
class Magic : public Skill {
public:
    /**
     * @brief Constructor
     * @param name Spell name
     * @param description Spell description
     * @param manaCost Mana cost to cast the spell
     * @param power Spell power level
     */
    Magic(const std::string& name = "", const std::string& description = "", int manaCost = 0, int power = 0);
    
    /**
     * @brief Cast the spell
     * @param p Reference to the player casting the spell
     * @param e Reference to the target enemy
     * 
     * Executes the spell effect on the specified targets.
     */
    void Cast(Player& p, Enemy& e);
    
    /**
     * @brief Get mana cost
     * @return Mana required to cast the spell
     */
    int GetManaCost() const;
    
    /**
     * @brief Enchant an item
     * @param item Item to enchant
     * 
     * Applies magical enhancement to the specified item.
     */
    void Enchant(Item& item);
    
    /**
     * @brief Upgrade the spell
     * 
     * Improves spell power and reduces mana cost.
     */
    void Upgrade();
    
    /**
     * @brief Apply cooldown to spell
     * 
     * Puts the spell on cooldown, making it temporarily unavailable.
     */
    void Cooldown();

private:
    int manaCost;       ///< Mana cost to cast the spell
    int power;          ///< Spell power level
};

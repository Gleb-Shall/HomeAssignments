/**
 * @file Skill.h
 * @brief Base skill class
 * @author Gleb Shikunov
 */

#pragma once
#include "Player.h"
#include "Enemy.h"
#include <string>

/**
 * @class Skill
 * @brief Base class for player skills and abilities
 * 
 * This class represents the base functionality for all player skills,
 * including cooldown management, cost tracking, and upgrade capabilities.
 */
class Skill {
public:
    /**
     * @brief Constructor
     * @param name Skill name
     * @param description Skill description
     * @param cost Skill cost (mana, energy, etc.)
     */
    Skill(const std::string& name = "", const std::string& description = "", int cost = 0);
    
    /**
     * @brief Get skill cost
     * @return Cost required to use the skill
     */
    int GetCost() const;
    
    /**
     * @brief Upgrade the skill
     * 
     * Improves the skill's effectiveness and reduces cost.
     */
    void Upgrade();
    
    /**
     * @brief Get skill description
     * @return Description of the skill
     */
    std::string GetDescription() const;
    
    /**
     * @brief Apply cooldown to skill
     * 
     * Puts the skill on cooldown, making it temporarily unavailable.
     */
    void Cooldown();
    
    /**
     * @brief Get skill name
     * @return Name of the skill
     */
    std::string GetName() const;
    
    /**
     * @brief Get current cooldown
     * @return Remaining cooldown turns
     */
    int GetCooldown() const;

private:
    std::string name;           ///< Skill name
    std::string description;    ///< Skill description
    int cost;                   ///< Cost to use the skill
    int cooldown;               ///< Current cooldown turns
};

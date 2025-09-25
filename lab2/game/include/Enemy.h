/**
 * @file Enemy.h
 * @brief Enemy character class
 * @author Gleb Shikunov
 */

#pragma once
class Player; // forward declare

/**
 * @class Enemy
 * @brief Enemy character that can fight the player
 * 
 * This class represents enemies in the game that can engage in combat
 * with the player. Enemies have AI behavior, can defend, and may have
 * special abilities like magical attacks or buffs.
 */
class Enemy {
public:
    /**
     * @brief Default constructor
     * 
     * Creates an enemy with default stats.
     */
    Enemy();
    
    /**
     * @brief Constructor with custom stats
     * @param health Initial health points
     * @param attack Attack power
     */
    Enemy(int health, int attack);
    
    /**
     * @brief Attack the player
     * @param player Reference to the player to attack
     * 
     * Performs an attack against the player, dealing damage
     * based on the enemy's attack power.
     */
    void Attack(Player& player);
    
    /**
     * @brief Defend against incoming attacks
     * 
     * Sets the enemy in a defensive stance, reducing incoming damage.
     */
    void Defend();
    
    /**
     * @brief AI decision making
     * @param player Reference to the player
     * 
     * Determines the enemy's next action based on current situation
     * and player state.
     */
    void Think(Player& player);
    
    /**
     * @brief Take damage
     * @param dmg Amount of damage to take
     * 
     * Reduces enemy's HP by the specified amount.
     */
    void TakeDamage(int dmg);
    
    /**
     * @brief Drop loot when defeated
     * 
     * Handles loot dropping when the enemy is defeated.
     */
    void DropLoot();

    /**
     * @brief Get current HP
     * @return Current hit points
     */
    int GetHP() const;
    
    /**
     * @brief Check if enemy is dead
     * @return True if HP is 0 or below
     */
    bool IsDead() const { return hp <= 0; }
    
    /**
     * @brief Check if enemy has buff
     * @return True if enemy has an active buff
     */
    bool HasBuff() const;
    
    /**
     * @brief Set magical status
     * @param magical Whether the enemy is magical
     */
    void SetMagical(bool magical) { isMagical = magical; }
    
    /**
     * @brief Check if enemy is magical
     * @return True if enemy has magical abilities
     */
    bool IsMagical() const { return isMagical; }
    
    /**
     * @brief Reset enemy to initial state
     * 
     * Restores enemy to full health and resets all status effects.
     */
    void Reset();

private:
    int hp;                 ///< Current hit points
    int attackPower;        ///< Attack power
    bool defending;         ///< Whether enemy is defending
    bool isMagical;         ///< Whether enemy has magical abilities
    bool hasBuff;           ///< Whether enemy has an active buff
};

/**
 * @file Battle.h
 * @brief Battle system class
 * @author Gleb Shikunov
 */

#pragma once
#include "Player.h"
#include "Enemy.h"

class World; // Forward declaration

/**
 * @class Battle
 * @brief Manages turn-based combat between player and enemy
 * 
 * This class handles the combat system, managing turns, actions,
 * and determining battle outcomes between the player and enemies.
 */
class Battle {
public:
    /**
     * @brief Default constructor
     * 
     * Initializes battle with null pointers and inactive state.
     */
    Battle() : player(nullptr), enemy(nullptr), world(nullptr), active(false) {}
    
    /**
     * @brief Start a battle
     * @param p Reference to the player
     * @param e Reference to the enemy
     * @param w Reference to the world
     * 
     * Initializes a new battle between the specified player and enemy.
     */
    void Start(Player& p, Enemy& e, World& w);
    
    /**
     * @brief Process player's turn
     * 
     * Handles player actions during their turn in combat.
     */
    void PlayerTurn();
    
    /**
     * @brief Process enemy's turn
     * 
     * Handles enemy AI actions during their turn in combat.
     */
    void EnemyTurn();
    
    /**
     * @brief Check if battle is won
     * @return True if player has won the battle
     */
    bool CheckWin();
    
    /**
     * @brief End the battle
     * 
     * Cleans up battle state and returns to normal gameplay.
     */
    void End();
    
    /**
     * @brief Check if battle is active
     * @return True if battle is currently ongoing
     */
    bool IsActive() const { return active; }

private:
    Player* player;     ///< Pointer to the player in battle
    Enemy* enemy;       ///< Pointer to the enemy in battle
    World* world;       ///< Pointer to the world for context
    bool active;        ///< Whether battle is currently active
};

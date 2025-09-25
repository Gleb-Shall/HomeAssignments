/**
 * @file Game.h
 * @brief Main game controller class
 * @author Gleb Shikunov
 */

#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"
#include "World.h"

/**
 * @class Game
 * @brief Main game controller managing the entire game process
 * 
 * This class is the central controller for the RPG game, managing the game loop,
 * player interactions, combat system, and world state. It coordinates between
 * all major game systems including Player, Enemy, Battle, and World.
 */
class Game {
public:
    /**
     * @brief Initialize the game
     * 
     * Sets up initial game state, creates player, generates world,
     * and prepares all game systems for play.
     */
    void Init();
    
    /**
     * @brief Main game loop
     * 
     * Runs the primary game loop handling user input, game updates,
     * and rendering until the game is exited.
     */
    void Run();
    
    /**
     * @brief Render the current game state
     * 
     * Displays the current game interface including player stats,
     * world map, and available commands.
     */
    void Render();
    
    /**
     * @brief Update game state
     * 
     * Processes game logic updates including enemy movement,
     * quest progression, and world state changes.
     */
    void Update();
    
    /**
     * @brief Exit the game
     * 
     * Cleanly shuts down the game, saves progress if needed,
     * and exits the application.
     */
    void Exit();

private:
    /**
     * @brief Print help information
     * 
     * Displays available commands and game instructions to the player.
     */
    void PrintHelp();
    
    /**
     * @brief Handle user command
     * @param line The command string entered by the user
     * 
     * Processes and executes user commands including movement,
     * combat actions, and system interactions.
     */
    void HandleCommand(const std::string& line);
    
    /**
     * @brief Show shop interface
     * 
     * Displays available items for purchase and handles shop interactions.
     */
    void ShowShop();
    
    /**
     * @brief Buy an item from shop
     * @param name Name of the item to purchase
     * 
     * Handles item purchase logic including gold deduction and inventory updates.
     */
    void BuyItem(const std::string& name);
    
    /**
     * @brief Sell an item to shop
     * @param name Name of the item to sell
     * 
     * Handles item selling logic including gold addition and inventory updates.
     */
    void SellItem(const std::string& name);
    
    /**
     * @brief Use a skill
     * @param name Name of the skill to use
     * 
     * Executes skill usage including cooldown management and effect application.
     */
    void UseSkill(const std::string& name);
    
    /**
     * @brief Cast a spell
     * @param name Name of the spell to cast
     * 
     * Executes spell casting including mana cost and effect application.
     */
    void CastSpell(const std::string& name);

    // Game state variables
    bool inBattle = false;                    ///< Whether player is currently in combat
    int bonusNoAttackTurns = 0;              ///< Extra turns without attack after run/defend
    Player player;                           ///< Main player character
    Enemy enemy;                             ///< Current enemy in combat
    Battle battle;                           ///< Battle system controller
    World world;                             ///< Game world and map manager
    
    // Quest system
    bool questActive = false;                ///< Whether first quest is active
    bool questCompleted = false;             ///< Whether first quest is completed
    bool secondQuestActive = false;          ///< Whether second quest is active
    bool secondQuestCompleted = false;       ///< Whether second quest is completed
    bool gameFinished = false;               ///< Whether game has been completed
    
    // Shop system
    std::vector<std::pair<std::string,int>> shopGoods; ///< Available shop items (name, price)
    
    // Battle positioning
    int battleEnemyX = -1;                   ///< X coordinate of enemy in battle
    int battleEnemyY = -1;                   ///< Y coordinate of enemy in battle
};

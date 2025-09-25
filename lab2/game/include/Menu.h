/**
 * @file Menu.h
 * @brief User interface menu system
 * @author Gleb Shikunov
 */

#pragma once

/**
 * @class Menu
 * @brief User interface menu system
 * 
 * This class manages all game menus including main menu,
 * inventory, stats, battle menu, and shop interface.
 */
class Menu {
public:
    /**
     * @brief Show main menu
     * 
     * Displays the main game menu with available options.
     */
    void ShowMain();
    
    /**
     * @brief Show inventory menu
     * 
     * Displays player's inventory and item management options.
     */
    void ShowInventory();
    
    /**
     * @brief Show player stats
     * 
     * Displays player's current statistics and abilities.
     */
    void ShowStats();
    
    /**
     * @brief Handle user input
     * 
     * Processes user input for menu navigation and selection.
     */
    void HandleInput();
    
    /**
     * @brief Exit current menu
     * 
     * Closes the current menu and returns to previous screen.
     */
    void ExitMenu();
    
    /**
     * @brief Show battle menu
     * 
     * Displays combat options during battle.
     */
    void ShowBattleMenu();
    
    /**
     * @brief Show shop menu
     * 
     * Displays shop interface for buying and selling items.
     */
    void ShowShopMenu();
};

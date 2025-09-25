/**
 * @file NPC.h
 * @brief Non-player character class
 * @author Gleb Shikunov
 */

#pragma once
#include "Player.h"
#include "Item.h"
#include <string>

/**
 * @class NPC
 * @brief Non-player character for interactions and quests
 * 
 * This class represents NPCs that can interact with the player,
 * provide quests, and give rewards for quest completion.
 */
class NPC {
public:
    /**
     * @brief Constructor
     * @param name NPC name
     * @param dialog Default dialog text
     */
    NPC(const std::string& name = "NPC", const std::string& dialog = "Привет!");
    
    /**
     * @brief Talk to the NPC
     * 
     * Initiates conversation with the NPC and displays dialog.
     */
    void Talk();
    
    /**
     * @brief Give quest to player
     * 
     * Assigns a quest to the player if the NPC has one available.
     */
    void GiveQuest();
    
    /**
     * @brief Receive item from player
     * @param item Item to receive
     * 
     * Handles item transfer from player to NPC.
     */
    void ReceiveItem(Item& item);
    
    /**
     * @brief Give reward to player
     * @param p Reference to the player
     * 
     * Provides quest rewards to the player upon quest completion.
     */
    void Reward(Player& p);
    
    /**
     * @brief Get NPC name
     * @return NPC name
     */
    std::string GetName() const;
    
    /**
     * @brief Check if NPC has quest
     * @return True if NPC has an available quest
     */
    bool HasQuest() const;
    
    /**
     * @brief Complete the quest
     * 
     * Marks the quest as completed and updates NPC state.
     */
    void CompleteQuest();

private:
    std::string name;           ///< NPC name
    std::string dialog;         ///< NPC dialog text
    bool hasQuest;              ///< Whether NPC has an available quest
    bool questCompleted;        ///< Whether the quest has been completed
};

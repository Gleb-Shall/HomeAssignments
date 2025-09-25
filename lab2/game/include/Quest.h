/**
 * @file Quest.h
 * @brief Quest system class
 * @author Gleb Shikunov
 */

#pragma once
#include "Player.h"
#include <string>

/**
 * @class Quest
 * @brief Represents a quest or task for the player
 * 
 * This class manages quest state, completion tracking,
 * and reward distribution to players.
 */
class Quest {
public:
    /**
     * @brief Constructor
     * @param description Quest description
     * @param reward Reward amount for completion
     */
    Quest(const std::string& description = "", int reward = 0);
    
    /**
     * @brief Complete the quest
     * @param p Reference to the player completing the quest
     * 
     * Marks the quest as completed and gives rewards to the player.
     */
    void Complete(Player& p);
    
    /**
     * @brief Get quest description
     * @return Description of the quest
     */
    std::string GetDescription() const;
    
    /**
     * @brief Get quest reward
     * @return Reward amount for completing the quest
     */
    int GetReward() const;
    
    /**
     * @brief Check if quest is started
     * @return True if quest has been started
     */
    bool IsStarted() const;
    
    /**
     * @brief Check if quest is completed
     * @return True if quest has been completed
     */
    bool IsCompleted() const;

private:
    std::string description;    ///< Quest description text
    int reward;                 ///< Reward amount for completion
    bool started;               ///< Whether quest has been started
    bool completed;             ///< Whether quest has been completed
};

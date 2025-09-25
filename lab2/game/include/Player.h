/**
 * @file Player.h
 * @brief Player character class
 * @author Gleb Shikunov
 */

#pragma once
#include <string>
#include <vector>
class Item; // forward declare
class Enemy; // forward declare

/**
 * @class Player
 * @brief Main player character with stats, inventory, and abilities
 * 
 * This class represents the player character in the RPG game. It manages
 * all player-related functionality including combat stats, inventory,
 * equipment, skills, and progression systems.
 */
class Player {
public:
    /**
     * @brief Default constructor
     * 
     * Initializes player with default stats and empty inventory.
     */
    Player();
    
    /**
     * @brief Attack an enemy
     * @param enemy Reference to the enemy to attack
     * 
     * Performs an attack against the specified enemy, dealing damage
     * based on player's attack power and weapon.
     */
    void Attack(Enemy& enemy);
    
    /**
     * @brief Defend against incoming attacks
     * 
     * Sets the player in a defensive stance, reducing incoming damage
     * for the next attack received.
     */
    void Defend();
    
    /**
     * @brief Use an item
     * @param item Reference to the item to use
     * 
     * Applies the effects of the specified item to the player.
     */
    void UseItem(Item& item);
    
    /**
     * @brief Move the player
     * @param dx X direction movement (-1, 0, or 1)
     * @param dy Y direction movement (-1, 0, or 1)
     * 
     * Attempts to move the player in the specified direction.
     */
    void Move(int dx, int dy);
    
    /**
     * @brief Level up the player
     * 
     * Increases player level and improves stats including HP, mana, and attack power.
     */
    void LevelUp();

    // Health and combat methods
    /**
     * @brief Take damage
     * @param dmg Amount of damage to take
     * 
     * Reduces player's HP by the specified amount, considering armor defense.
     */
    void TakeDamage(int dmg);
    
    /**
     * @brief Heal the player
     * @param amount Amount of HP to restore
     * 
     * Restores player's HP by the specified amount, not exceeding max HP.
     */
    void Heal(int amount);
    
    /**
     * @brief Get current HP
     * @return Current hit points
     */
    int GetHP() const;
    
    /**
     * @brief Check if player is defending
     * @return True if player is in defensive stance
     */
    bool IsDefending() const;
    
    // Economy and inventory methods
    /**
     * @brief Add gold to player
     * @param amount Amount of gold to add
     */
    void AddGold(int amount);
    
    /**
     * @brief Get current gold amount
     * @return Current gold count
     */
    int GetGold() const;
    
    /**
     * @brief Add item to inventory
     * @param name Name of the item to add
     */
    void AddItem(const std::string& name);
    
    /**
     * @brief Get player's inventory
     * @return Reference to inventory vector
     */
    const std::vector<std::string>& GetInventory() const;
    
    /**
     * @brief Equip a weapon
     * @param name Name of the weapon to equip
     * @return True if weapon was successfully equipped
     */
    bool Equip(const std::string& name);
    
    /**
     * @brief Get currently equipped weapon
     * @return Name of equipped weapon
     */
    std::string GetEquipped() const;
    
    /**
     * @brief Check if player has an item
     * @param name Name of the item to check for
     * @return True if player has the item
     */
    bool HasItem(const std::string& name) const;
    
    /**
     * @brief Remove item from inventory by name
     * @param name Name of the item to remove
     * @return True if item was successfully removed
     */
    bool RemoveItemByName(const std::string& name);
    
    /**
     * @brief Get player level
     * @return Current player level
     */
    int GetLevel() const { return level; }
    
    /**
     * @brief Get current mana
     * @return Current mana points
     */
    int GetMana() const { return mana; }
    
    /**
     * @brief Get maximum HP
     * @return Maximum hit points
     */
    int GetMaxHp() const { return maxHp; }
    
    /**
     * @brief Get maximum mana
     * @return Maximum mana points
     */
    int GetMaxMana() const { return maxMana; }
    
    /**
     * @brief Restore mana
     * @param amount Amount of mana to restore
     * 
     * Restores player's mana by the specified amount, not exceeding max mana.
     */
    void RestoreMana(int amount);
    
    // Buff system methods
    /**
     * @brief Add a buff to the player
     * @param buffName Name of the buff
     * @param power Power level of the buff
     * @param duration Duration in turns
     */
    void AddBuff(const std::string& buffName, int power, int duration);
    
    /**
     * @brief Remove a buff from the player
     * @param buffName Name of the buff to remove
     */
    void RemoveBuff(const std::string& buffName);
    
    /**
     * @brief Check if player has a specific buff
     * @param buffName Name of the buff to check for
     * @return True if player has the buff
     */
    bool HasBuff(const std::string& buffName) const;
    
    /**
     * @brief Get buff power level
     * @param buffName Name of the buff
     * @return Power level of the buff, or 0 if not found
     */
    int GetBuffPower(const std::string& buffName) const;
    
    // Upgrade methods
    /**
     * @brief Upgrade player's weapon
     * 
     * Improves the currently equipped weapon's damage and durability.
     */
    void UpgradeWeapon();
    
    /**
     * @brief Upgrade player's armor
     * 
     * Improves the currently equipped armor's defense and durability.
     */
    void UpgradeArmor();
    
    /**
     * @brief Get number of weapon upgrades
     * @return Number of times weapon has been upgraded
     */
    int GetWeaponUpgrades() const { return weaponUpgrades; }
    
    /**
     * @brief Get number of armor upgrades
     * @return Number of times armor has been upgraded
     */
    int GetArmorUpgrades() const { return armorUpgrades; }
    
    // Armor methods
    /**
     * @brief Equip armor
     * @param name Name of the armor to equip
     */
    void EquipArmor(const std::string& name);
    
    /**
     * @brief Get currently equipped armor
     * @return Name of equipped armor
     */
    std::string GetEquippedArmor() const { return equippedArmor; }
    
    /**
     * @brief Get armor defense value
     * @return Total defense value from equipped armor
     */
    int GetArmorDefense() const;
    
    // Artifact methods
    /**
     * @brief Equip an artifact
     * @param name Name of the artifact to equip
     */
    void EquipArtifact(const std::string& name);
    
    /**
     * @brief Get currently equipped artifact
     * @return Name of equipped artifact
     */
    std::string GetEquippedArtifact() const { return equippedArtifact; }
private:
    // Core stats
    int hp;                         ///< Current hit points
    int maxHp;                      ///< Maximum hit points
    int mana;                       ///< Current mana points
    int maxMana;                    ///< Maximum mana points
    int level;                      ///< Player level
    int attackPower;                ///< Base attack power
    bool defending;                 ///< Whether player is defending
    
    // Economy
    int gold;                       ///< Current gold amount
    std::vector<std::string> inventory; ///< Player's item inventory
    
    // Equipment slots
    std::string equipped;           ///< Currently equipped weapon
    std::string equippedArmor;      ///< Currently equipped armor
    std::string equippedArtifact;   ///< Currently equipped artifact
    
    // Upgrade tracking
    int weaponUpgrades;             ///< Number of weapon upgrades
    int armorUpgrades;              ///< Number of armor upgrades
    
    /**
     * @struct Buff
     * @brief Represents a temporary buff effect
     */
    struct Buff {
        std::string name;           ///< Name of the buff
        int power;                  ///< Power level of the buff
        int duration;               ///< Duration in turns
    };
    std::vector<Buff> buffs;        ///< Active buffs on the player
};

/**
 * @file Item.h
 * @brief Base item class
 * @author Gleb Shikunov
 */

#pragma once
#include <string>
class Player;

/**
 * @class Item
 * @brief Abstract base class for all items in the game
 * 
 * This class serves as the base for all items including weapons, armor,
 * potions, and other game objects. It provides a common interface for
 * item usage, description, and cloning functionality.
 */
class Item {
public:
    /**
     * @brief Constructor
     * @param name Item name
     * @param description Item description
     * @param value Item value in gold
     */
    Item(const std::string& name = "", const std::string& description = "", int value = 0);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Item() = default;
    
    /**
     * @brief Use the item
     * @param p Reference to the player using the item
     * 
     * Pure virtual method that must be implemented by derived classes
     * to define specific item behavior when used.
     */
    virtual void Use(Player& p);
    
    /**
     * @brief Get item name
     * @return Item name
     */
    virtual std::string GetName() const;
    
    /**
     * @brief Get item description
     * @return Item description
     */
    virtual std::string GetDescription() const;
    
    /**
     * @brief Get item value
     * @return Item value in gold
     */
    virtual int GetValue() const;
    
    /**
     * @brief Clone the item
     * @return Pointer to a new copy of the item
     * 
     * Creates a deep copy of the item. Must be implemented by derived classes.
     */
    virtual Item* Clone() const;

protected:
    std::string name;           ///< Item name
    std::string description;    ///< Item description
    int value;                  ///< Item value in gold
};

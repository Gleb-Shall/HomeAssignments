/**
 * @file MapTile.h
 * @brief Individual map tile class
 * @author Gleb Shikunov
 */

#pragma once

/**
 * @class MapTile
 * @brief Represents a single tile in the game world
 * 
 * This class manages individual map tiles, including their type,
 * walkability, and occupancy status.
 */
class MapTile {
public:
    /**
     * @brief Default constructor
     * 
     * Creates a walkable, unoccupied tile with default type '.'.
     */
    MapTile() : type('.'), occupied(false), walkable(true) {}
    
    /**
     * @brief Check if tile is walkable
     * @return True if tile can be walked on and is not occupied
     */
    bool IsWalkable() const { return walkable && !occupied; }
    
    /**
     * @brief Set tile type
     * @param t Character representing the tile type
     */
    void SetType(char t) { type = t; }
    
    /**
     * @brief Get tile type
     * @return Character representing the tile type
     */
    char GetType() const { return type; }
    
    /**
     * @brief Set occupancy status
     * @param o Whether the tile is occupied
     */
    void SetOccupied(bool o) { occupied = o; }
    
    /**
     * @brief Check if tile is occupied
     * @return True if tile is occupied by an entity
     */
    bool IsOccupied() const { return occupied; }
    
    /**
     * @brief Set walkability
     * @param w Whether the tile can be walked on
     */
    void SetWalkable(bool w) { walkable = w; }

private:
    char type;          ///< Character representing tile type
    bool occupied;      ///< Whether tile is occupied by an entity
    bool walkable;      ///< Whether tile can be walked on
};

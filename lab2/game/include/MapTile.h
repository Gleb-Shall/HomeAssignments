#pragma once

class MapTile {
public:
    MapTile() : type('.'), occupied(false), walkable(true) {}
    bool IsWalkable() const { return walkable && !occupied; }
    void SetType(char t) { type = t; }
    char GetType() const { return type; }
    void SetOccupied(bool o) { occupied = o; }
    bool IsOccupied() const { return occupied; }
    void SetWalkable(bool w) { walkable = w; }
private:
    char type;
    bool occupied;
    bool walkable;
};

#include "World.h"
#include <iostream>

void World::SpawnSecondNPC() {
    // Spawn second NPC in another corner of the map
    secondNPCX = 9;
    secondNPCY = 9;
    hasSecondNPC = true;
    grid[secondNPCY][secondNPCX].SetType('N');
    grid[secondNPCY][secondNPCX].SetOccupied(true);
    std::cout << "Second NPC appeared in the corner of the map!" << std::endl;
}

bool World::IsNearSecondNPC() const {
    return hasSecondNPC && std::max(std::abs(playerX - secondNPCX), std::abs(playerY - secondNPCY)) <= 1;
}

void World::SpawnDragon() {
    // Spawn dragon in the center of the map
    dragonX = 5;
    dragonY = 5;
    hasDragon = true;
    dragonDefeated = false;
    grid[dragonY][dragonX].SetType('D');
    grid[dragonY][dragonX].SetOccupied(true);
    std::cout << "Mighty Dragon appeared in the center of the map!" << std::endl;
}

bool World::IsDragonDefeated() const {
    return dragonDefeated;
}

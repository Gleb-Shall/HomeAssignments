#include "Battle.h"
#include "World.h"
#include <iostream>
#include <cstdlib>

void Battle::Start(Player& p, Enemy& e, World& w) {
    // Check if there's an enemy on the map before starting battle
    if (!w.HasEnemy() && !w.HasDragon()) {
        std::cout << "No enemy nearby to attack!" << std::endl;
        return; // Don't start battle if no enemy on map
    }
    
    player = &p;
    enemy = &e;
    world = &w;
    active = true;
    std::cout << "Battle started!" << std::endl;
}

void Battle::PlayerTurn() {
    if (!player || !enemy) return;
    // simple logic: if player is healthy, attacks, sometimes defends
    if (enemy->GetHP() > 0) {
        player->Attack(*enemy);
    }
}

void Battle::EnemyTurn() {
    if (!player || !enemy) return;
    if (player->GetHP() > 0) {
        enemy->Attack(*player);
    }
}

bool Battle::CheckWin() {
    if (!player || !enemy) return true;
    if (enemy->GetHP() <= 0) { std::cout << "Victory!" << std::endl; return true; }
    if (player->GetHP() <= 0) { std::cout << "Defeat..." << std::endl; return true; }
    return false;
}

void Battle::End() {
    active = false;
    player = nullptr;
    enemy = nullptr;
    std::cout << "Battle ended." << std::endl;
}

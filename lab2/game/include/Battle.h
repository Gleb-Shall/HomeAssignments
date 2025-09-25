#pragma once
#include "Player.h"
#include "Enemy.h"

class World; // Forward declaration

class Battle {
public:
    Battle() : player(nullptr), enemy(nullptr), world(nullptr), active(false) {}
    void Start(Player& p, Enemy& e, World& w);
    void PlayerTurn();
    void EnemyTurn();
    bool CheckWin();
    void End();
    bool IsActive() const { return active; }
private:
    Player* player;
    Enemy* enemy;
    World* world;
    bool active;
};

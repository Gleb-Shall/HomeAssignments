#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"
#include "World.h"

class Game {
public:
    void Init();
    void Run();
    void Render();
    void Update();
    void Exit();
private:
    void PrintHelp();
    void HandleCommand(const std::string& line);
    void ShowShop();
    void BuyItem(const std::string& name);
    void SellItem(const std::string& name);
    void UseSkill(const std::string& name);
    void CastSpell(const std::string& name);
    bool inBattle = false;
    int bonusNoAttackTurns = 0; // дополнительный ход без атаки после run/defend
    Player player;
    Enemy enemy;
    Battle battle;
    World world;
    // bool inShop = false; // Unused field - commented out
    bool questActive = false;
    bool questCompleted = false;
    bool secondQuestActive = false;
    bool secondQuestCompleted = false;
    bool gameFinished = false;
    // simple shop: name -> price
    std::vector<std::pair<std::string,int>> shopGoods;
    // int battleEnemyIdx = -1; // Unused field - commented out
    int battleEnemyX = -1;
    int battleEnemyY = -1;
};

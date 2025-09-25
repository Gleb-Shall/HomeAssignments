#pragma once
#include "Player.h"
#include "Enemy.h"
#include <string>

class Skill {
public:
    Skill(const std::string& name = "", const std::string& description = "", int cost = 0);
    int GetCost() const;
    void Upgrade();
    std::string GetDescription() const;
    void Cooldown();
    std::string GetName() const;
    int GetCooldown() const;
private:
    std::string name;
    std::string description;
    int cost;
    int cooldown;
};

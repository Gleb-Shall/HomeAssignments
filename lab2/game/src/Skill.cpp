#include "Skill.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

Skill::Skill(const std::string& name, const std::string& description, int cost) 
    : name(name), description(description), cost(cost), cooldown(0) {}


int Skill::GetCost() const {
    return cost;
}

void Skill::Upgrade() {
    cost -= 2;
    if (cost < 1) cost = 1;
    std::cout << "Навык улучшен! Стоимость маны: " << cost << std::endl;
}

std::string Skill::GetDescription() const {
    return description;
}

void Skill::Cooldown() {
    if (cooldown > 0) cooldown--;
}

std::string Skill::GetName() const {
    return name;
}

int Skill::GetCooldown() const {
    return cooldown;
}

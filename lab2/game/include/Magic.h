#pragma once
#include "Skill.h"
#include "Item.h"

class Magic : public Skill {
public:
    Magic(const std::string& name = "", const std::string& description = "", int manaCost = 0, int power = 0);
    void Cast(Player& p, Enemy& e);
    int GetManaCost() const;
    void Enchant(Item& item);
    void Upgrade();
    void Cooldown();
private:
    int manaCost;
    int power;
};

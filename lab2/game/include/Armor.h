#pragma once
#include "Item.h"
#include "Player.h"

class Armor : public Item {
public:
    Armor(const std::string& name = "", const std::string& description = "", int value = 0, int defense = 0);
    int GetDefense() const;
    void Upgrade();
    void Break();
    void Repair();
    void Use(Player& p) override;
    Armor* Clone() const override;
    int GetDurability() const { return durability; }
    int GetMaxDurability() const { return maxDurability; }
private:
    int defense;
    int durability;
    int maxDurability;
};

#pragma once
#include "Item.h"
#include "Player.h"

class Weapon : public Item {
public:
    Weapon(const std::string& name = "", const std::string& description = "", int value = 0, int damage = 0);
    int GetDamage() const;
    void Upgrade();
    void Break();
    void Repair();
    void Use(Player& p) override;
    Weapon* Clone() const override;
    int GetDurability() const { return durability; }
    int GetMaxDurability() const { return maxDurability; }
private:
    int damage;
    int durability;
    int maxDurability;
};

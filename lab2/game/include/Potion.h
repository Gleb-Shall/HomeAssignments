#pragma once
#include "Item.h"
#include "Player.h"
#include <string>

class Potion : public Item {
public:
    Potion(const std::string& name = "", const std::string& description = "", int value = 0, 
           const std::string& effect = "", int power = 0);
    void Drink(Player& p);
    std::string GetEffect() const;
    bool IsExpired() const;
    void Use(Player& p) override;
    Potion* Clone() const override;
private:
    std::string effect;
    int power;
    bool expired;
};

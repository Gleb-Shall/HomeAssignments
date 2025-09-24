#include "Potion.h"
#include "Player.h"
#include <iostream>

Potion::Potion(const std::string& name, const std::string& description, int value, const std::string& effect, int power)
    : Item(name, description, value), effect(effect), power(power), expired(false) {}

void Potion::Drink(Player& player) {
    if (expired) {
        std::cout << "Зелье испортилось!" << std::endl;
        return;
    }
    
    if (effect == "heal") {
        player.Heal(power);
    } else if (effect == "mana") {
        player.RestoreMana(power);
    } else if (effect == "strength") {
        player.AddBuff("strength", power, 3);
    }
    
    std::cout << "Вы выпили: " << GetName() << std::endl;
    expired = true;
}

std::string Potion::GetEffect() const {
    return effect;
}


bool Potion::IsExpired() const {
    return expired;
}

void Potion::Use(Player& player) {
    Drink(player);
}

Potion* Potion::Clone() const {
    Potion* newPotion = new Potion(name, description, value, effect, power);
    newPotion->expired = expired;
    return newPotion;
}

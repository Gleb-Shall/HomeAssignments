#include "Magic.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include <iostream>

Magic::Magic(const std::string& name, const std::string& description, int manaCost, int power) 
    : Skill(name, description, manaCost), manaCost(manaCost), power(power) {}

void Magic::Cast(Player& player, Enemy& enemy) {
    if (GetCooldown() > 0) {
        std::cout << "Заклинание на перезарядке! Осталось: " << GetCooldown() << " ходов" << std::endl;
        return;
    }
    
    if (player.GetMana() < manaCost) {
        std::cout << "Недостаточно маны для заклинания!" << std::endl;
        return;
    }
    
    // Используем ману
    player.RestoreMana(-manaCost);
    
    // Применяем эффект заклинания
    if (GetName() == "Fireball") {
        enemy.TakeDamage(power);
        std::cout << "Огненный шар наносит " << power << " урона!" << std::endl;
    } else if (GetName() == "Heal") {
        player.Heal(power);
        std::cout << "Лечение восстанавливает " << power << " HP!" << std::endl;
    } else if (GetName() == "Lightning") {
        enemy.TakeDamage(power);
        std::cout << "Молния наносит " << power << " урона!" << std::endl;
    }
    
    // Устанавливаем перезарядку
    Cooldown();
    std::cout << "Заклинание " << GetName() << " применено!" << std::endl;
}

int Magic::GetManaCost() const {
    return manaCost;
}

void Magic::Enchant(Item& item) {
    std::cout << "Предмет " << item.GetName() << " зачарован магией!" << std::endl;
    // Здесь можно добавить логику улучшения предмета
}

void Magic::Upgrade() {
    Skill::Upgrade();
    power += 5;
    std::cout << "Заклинание улучшено! Сила: " << power << std::endl;
}

void Magic::Cooldown() {
    Skill::Cooldown();
}

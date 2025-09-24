#include "Inventory.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

void Inventory::Add(Item& item) {
    items.push_back(item.Clone());
    std::cout << "Добавлен предмет: " << item.GetName() << std::endl;
}

void Inventory::Remove(Item& item) {
    auto it = std::find_if(items.begin(), items.end(), 
        [&item](Item* i) { return i->GetName() == item.GetName(); });
    if (it != items.end()) {
        delete *it;
        items.erase(it);
        std::cout << "Удален предмет: " << item.GetName() << std::endl;
    }
}

Item* Inventory::Find(std::string name) {
    for (auto* item : items) {
        if (item->GetName() == name) {
            return item;
        }
    }
    return nullptr;
}

void Inventory::List() {
    if (items.empty()) {
        std::cout << "Инвентарь пуст." << std::endl;
        return;
    }
    
    std::cout << "Инвентарь:" << std::endl;
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << (i + 1) << ". " << items[i]->GetName() 
                  << " - " << items[i]->GetDescription() 
                  << " (Цена: " << items[i]->GetValue() << ")" << std::endl;
    }
}

void Inventory::UseItem(std::string name) {
    Item* item = Find(name);
    if (item) {
        // Здесь нужно передать ссылку на игрока, но для простоты оставим заглушку
        std::cout << "Используется предмет: " << name << std::endl;
    } else {
        std::cout << "Предмет не найден: " << name << std::endl;
    }
}

Inventory::~Inventory() {
    for (auto* item : items) {
        delete item;
    }
}

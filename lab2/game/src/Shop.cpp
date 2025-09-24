#include "Shop.h"
#include "Player.h"
#include "Item.h"
#include <iostream>

void Shop::Buy(Player& player, Item& item) {
    if (player.GetGold() >= item.GetValue()) {
        player.AddGold(-item.GetValue());
        player.AddItem(item.GetName());
        std::cout << "Purchase completed: " << item.GetName() << " for " << item.GetValue() << " gold" << std::endl;
    } else {
        std::cout << "Not enough gold! Need: " << item.GetValue() << ", have: " << player.GetGold() << std::endl;
    }
}

void Shop::Sell(Player& player, Item& item) {
    if (player.HasItem(item.GetName())) {
        int sellPrice = item.GetValue() / 2;
        player.AddGold(sellPrice);
        player.RemoveItemByName(item.GetName());
        std::cout << "Sale completed: " << item.GetName() << " for " << sellPrice << " gold" << std::endl;
    } else {
        std::cout << "You don't have this item!" << std::endl;
    }
}

void Shop::ListGoods() {
    if (goods.empty()) {
        std::cout << "Shop is empty." << std::endl;
        return;
    }
    
    std::cout << "Shop goods:" << std::endl;
    for (size_t i = 0; i < goods.size(); ++i) {
        std::cout << (i + 1) << ". " << goods[i]->GetName() 
                  << " - " << goods[i]->GetDescription() 
                  << " (Price: " << goods[i]->GetValue() << ")" << std::endl;
    }
}

void Shop::AddItem(Item& item) {
    goods.push_back(item.Clone());
    std::cout << "Item added: " << item.GetName() << std::endl;
}

void Shop::RemoveItem(Item& item) {
    for (auto it = goods.begin(); it != goods.end(); ++it) {
        if ((*it)->GetName() == item.GetName()) {
            delete *it;
            goods.erase(it);
            std::cout << "Item removed: " << item.GetName() << std::endl;
            return;
        }
    }
    std::cout << "Item not found!" << std::endl;
}

Shop::~Shop() {
    for (auto* item : goods) {
        delete item;
    }
}

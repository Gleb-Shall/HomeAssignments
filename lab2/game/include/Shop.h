#pragma once
#include "Player.h"
#include "Item.h"
#include <vector>

class Shop {
public:
    ~Shop();
    void Buy(Player& p, Item& i);
    void Sell(Player& p, Item& i);
    void ListGoods();
    void AddItem(Item& i);
    void RemoveItem(Item& i);
    const std::vector<Item*>& GetGoods() const { return goods; }
private:
    std::vector<Item*> goods;
};

#pragma once
#include "Item.h"
#include <vector>
#include <string>

class Inventory {
public:
    ~Inventory();
    void Add(Item& item);
    void Remove(Item& item);
    Item* Find(std::string name);
    void List();
    void UseItem(std::string name);
    const std::vector<Item*>& GetItems() const { return items; }
private:
    std::vector<Item*> items;
};

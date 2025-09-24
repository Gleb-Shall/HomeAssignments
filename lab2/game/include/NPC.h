#pragma once
#include "Player.h"
#include "Item.h"
#include <string>

class NPC {
public:
    NPC(const std::string& name = "NPC", const std::string& dialog = "Привет!");
    void Talk();
    void GiveQuest();
    void ReceiveItem(Item& item);
    void Reward(Player& p);
    std::string GetName() const;
    bool HasQuest() const;
    void CompleteQuest();
private:
    std::string name;
    std::string dialog;
    bool hasQuest;
    bool questCompleted;
};

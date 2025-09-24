#include "NPC.h"
#include "Player.h"
#include "Item.h"
#include <iostream>

NPC::NPC(const std::string& name, const std::string& dialog) 
    : name(name), dialog(dialog), hasQuest(false), questCompleted(false) {}

void NPC::Talk() {
    std::cout << name << ": " << dialog << std::endl;
}


void NPC::GiveQuest() {
    if (!hasQuest) {
        hasQuest = true;
        std::cout << name << ": I have a quest for you!" << std::endl;
        std::cout << "Bring me a Goblin Ear, and I will reward you generously." << std::endl;
    } else if (!questCompleted) {
        std::cout << name << ": You haven't completed the quest yet." << std::endl;
    } else {
        std::cout << name << ": Thank you for completing the quest!" << std::endl;
    }
}

void NPC::ReceiveItem(Item& item) {
    std::cout << name << ": Thank you for " << item.GetName() << "!" << std::endl;
}

void NPC::Reward(Player& player) {
    if (questCompleted) {
        player.AddGold(50);
        std::cout << name << ": Here's your reward! +50 gold" << std::endl;
    }
}

std::string NPC::GetName() const {
    return name;
}

bool NPC::HasQuest() const {
    return hasQuest;
}

void NPC::CompleteQuest() {
    questCompleted = true;
    hasQuest = false;
}

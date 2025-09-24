#include "Quest.h"
#include "Player.h"
#include <iostream>

Quest::Quest(const std::string& description, int reward) 
    : description(description), reward(reward), started(false), completed(false) {}


void Quest::Complete(Player& player) {
    if (!completed) {
        if (!started) {
            started = true;
        }
        completed = true;
        player.AddGold(reward);
        std::cout << "Quest completed! Reward: " << reward << " gold" << std::endl;
    }
}


std::string Quest::GetDescription() const {
    return description;
}

int Quest::GetReward() const {
    return reward;
}

bool Quest::IsStarted() const {
    return started;
}

bool Quest::IsCompleted() const {
    return completed;
}

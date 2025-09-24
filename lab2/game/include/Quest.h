#pragma once
#include "Player.h"
#include <string>

class Quest {
public:
    Quest(const std::string& description = "", int reward = 0);
    void Complete(Player& p);
    std::string GetDescription() const;
    int GetReward() const;
    bool IsStarted() const;
    bool IsCompleted() const;
private:
    std::string description;
    int reward;
    bool started;
    bool completed;
};

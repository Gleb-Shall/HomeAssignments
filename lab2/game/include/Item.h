#pragma once
#include <string>
class Player;

class Item {
public:
    Item(const std::string& name = "", const std::string& description = "", int value = 0);
    virtual ~Item() = default;
    virtual void Use(Player& p);
    virtual std::string GetName() const;
    virtual std::string GetDescription() const;
    virtual int GetValue() const;
    virtual Item* Clone() const;
protected:
    std::string name;
    std::string description;
    int value;
};

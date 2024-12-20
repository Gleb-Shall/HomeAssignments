/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/

#include "Autobot.h"

Autobot::Autobot():
    Transformer(),
    _Commander("Default Commander"),
    Amount_of_kindness(0) 
{};

Autobot::Autobot(
    Gun* gun,
    const int &Influence_on_robots,
    const std::string &Name,
    const uint &Level,
    const uint &MaxHealth,
    const uint &TempHealth,
    const std::string &Commander,
    const int &amount_of_kindness
):
    Transformer(gun, Influence_on_robots, Name, Level, MaxHealth, TempHealth),
    _Commander(Commander),
    Amount_of_kindness(amount_of_kindness) 
{};

Autobot::~Autobot() = default;

std::string Autobot::get_Commander() const
{
    return _Commander;
}

void Autobot::set_Commander(const std::string &Commander)
{
    _Commander = Commander;
}

int Autobot::get_amount_of_kindness() const
{
    return Amount_of_kindness;
}

void Autobot::set_amount_of_kindness(const int &amount_of_kindness)
{
    Amount_of_kindness = amount_of_kindness;
}

void Autobot::call_Comander()
{
    std::cout << _Commander << ", I need help !!!\n";
}


bool Autobot::operator<(const Autobot& autobot)
{
    return get_TempHealth() < autobot.get_TempHealth();
}

bool Autobot::operator>(const Autobot& autobot)
{
    return  get_TempHealth() > autobot.get_TempHealth();
}

bool Autobot::operator==(const Autobot& autobot)
{
    return get_TempHealth() == autobot.get_TempHealth();
}


std::ostream& operator<<(std::ostream& os, const Autobot& autobot)
{
    os << "Autobot Commander: " << autobot.get_Commander() << ",\n";
    os << "Autobot amount_of_kindness: " << autobot.get_amount_of_kindness() << ",\n";
    os << "Autobot Name: " << autobot.get_Name() << ",\n";
    os << "Autobot Level: " << autobot.get_Level() << ",\n";
    os << "Autobot MaxHealth: " << autobot.get_Maxhealth() << ",\n";
    os << "Autobot TempHealth: " << autobot.get_TempHealth() << ",\n";
    os << "Autobot Gun: " << (*autobot.get_Gun());
    os << "Autobot Influence: " << autobot.get_Influence() << "\n";
    return os;
}

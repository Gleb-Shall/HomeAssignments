/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/

#include "Autobot.h"

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
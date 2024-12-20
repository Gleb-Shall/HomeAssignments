/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/

#include "Decepticon.h"

Decepticon::Decepticon(
    Gun* gun,
    const int &Influence_on_robots,
    const std::string &Name,
    const uint &Level,
    const uint &MaxHealth,
    const uint &TempHealth,
    const std::string &Commander,
    const int &amount_of_evil
):
    Transformer(gun, Influence_on_robots, Name, Level, MaxHealth, TempHealth),
    _Commander(Commander),
    Amount_of_evil(amount_of_evil) 
    {};

Decepticon::~Decepticon() = default;

std::string Decepticon::get_Commander() const
{
    return _Commander;
}

void Decepticon::set_Commander(const std::string &Commander)
{
    _Commander = Commander;
}

int Decepticon::get_amount_of_evil() const
{
    return Amount_of_evil;
}

void Decepticon::set_amount_of_evil(const int &amount_of_evil)
{
    Amount_of_evil = amount_of_evil;
}

void Decepticon::call_Comander()
{
    std::cout << _Commander << ", I need help !!!\n";
}
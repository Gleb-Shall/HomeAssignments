/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/

#include "Minicon.h"


Minicon::Minicon(
    Gun* gun,
    const int &Influence_on_robots,
    const std::string &Name,
    const uint &Level,
    const uint &MaxHealth,
    const uint &TempHealth,
    const std::string &Master,
    const int &number_of_important_things_to_do
):
    Transformer(gun, Influence_on_robots, Name, Level, MaxHealth, TempHealth),
    _Master(Master),
    Number_of_important_things_to_do(number_of_important_things_to_do) 
    {};

Minicon::~Minicon() = default;

std::string Minicon::get_Master() const
{
    return _Master;
}

void Minicon::set_Master(const std::string &Master)
{
    _Master = Master;
}

int Minicon::get_number_of_important_things_to_do() const
{
    return Number_of_important_things_to_do;
}

void Minicon::set_number_of_important_things_to_do(const int &number_of_important_things_to_do)
{
    Number_of_important_things_to_do = number_of_important_things_to_do;
}

void Minicon::call_Master()
{
    std::cout << _Master << ", I will help you!!!\n";
}
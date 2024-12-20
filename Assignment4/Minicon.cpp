/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
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


std::ostream& operator<<(std::ostream& os, const Minicon& minicon)
{
    os << "Minicon Master: " << minicon.get_Master() << ",\n";
    os << "Minicon Number_of_important_things_to_do: " << minicon.get_number_of_important_things_to_do() << ",\n";
    os << "Minicon Name: " << minicon.get_Name() << ",\n";
    os << "Minicon Level: " << minicon.get_Level() << ",\n";
    os << "Minicon MaxHealth: " << minicon.get_Maxhealth() << ",\n";
    os << "Minicon TempHealth: " << minicon.get_TempHealth() << ",\n";
    os << "Minicon Gun: " << minicon.get_Gun() << ".\n";
    os << "Minicon Influence: " << minicon.get_Influence() << ",\n";
    return os;
}

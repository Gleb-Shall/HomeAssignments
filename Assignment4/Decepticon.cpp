/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
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

std::ostream& Decepticon::operator<<(std::ostream& os, const Decepticon& decepticon)
{
    os << "Decepticon Commander: " << decepticon.get_Commander() << ",\n";
    os << "Decepticon Commander: " << decepticon.get_amount_of_evil() << ",\n";
    os << "Decepticon Name: " << decepticon.get_Name() << ",\n";
    os << "Decepticon Level: " << decepticon.get_Level() << ",\n";
    os << "Decepticon MaxHealth: " << decepticon.get_Maxhealth() << ",\n";
    os << "Decepticon TempHealth: " << decepticon.get_TempHealth() << ",\n";
    os << "Decepticon Gun: " << decepticon.get_Gun() << ".\n";
    os << "Decepticon Influence: " << decepticon.get_Influence() << ",\n";
    return os;
}

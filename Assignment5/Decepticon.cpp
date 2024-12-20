/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 5
*/

#include "Decepticon.h"

Decepticon::Decepticon():
    Transformer(),
    _Commander("Default Commander"),
    Amount_of_evil(0) 
{};

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


std::ostream& operator<<(std::ostream& os, const Decepticon& decepticon)
{
    os << "Decepticon Commander: " << decepticon.get_Commander() << ",\n";
    os << "Decepticon amount_of_evil: " << decepticon.get_amount_of_evil() << ",\n";
    os << "Decepticon Name: " << decepticon.get_Name() << ",\n";
    os << "Decepticon Level: " << decepticon.get_Level() << ",\n";
    os << "Decepticon MaxHealth: " << decepticon.get_Maxhealth() << ",\n";
    os << "Decepticon TempHealth: " << decepticon.get_TempHealth() << ",\n";
    os << "Decepticon Gun: " << (*decepticon.get_Gun());
    os << "Decepticon Influence: " << decepticon.get_Influence() << "\n";
    return os;
}

void Decepticon::transform()
{
    std::cout << "Decepticon, transform" << std::endl;
}

void Decepticon::ulta()
{
    std::cout << "Decepticon, ulta" << std::endl;
}

void Decepticon::openFire()
{
    std::cout << "Decepticon, openFire" << std::endl;
}

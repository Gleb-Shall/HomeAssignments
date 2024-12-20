/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#include "Transformer.h"


Transformer::Transformer(
    Gun* gun,
    const int &Influence_on_robots,
    const std::string &Name,
    const uint &Level,
    const uint &MaxHealth,
    const uint &TempHealth
    ):

    _Gun(gun),
    _Influence(Influence_on_robots),
    _Name(Name),
    _Level(Level),
    _MaxHealth(MaxHealth),
    _TempHealth(TempHealth)
{};

Transformer::~Transformer() = default;


bool Transformer::move()
{
    if (Transformer::IsAlife())
    {
        std::cout << "That was fast\n";
        return true;
    }
    std::cout << "On no, he catch hit\n";
    return false;
}


bool Transformer::IsAlife()
{
    if (Transformer::get_TempHealth() != 0)
    {
        std::cout << _Name << " is alive\n";
        return true;
    }
    std::cout << _Name << " is dead\n";
    return false;
}


Gun* Transformer::get_Gun() const
{
    return _Gun;
}
void Transformer::set_Gun(Gun* gun)
{
    _Gun = gun;
}
bool Transformer::fire()
{
    if (Transformer::IsAlife())
    {
        std::cout << _Name << " with " << _Gun->get_Name() << " dealt " << _Gun->get_Damage() << " damage\n";
        return true;
    }
    std::cout << _Name << " can not more fire\n";
    return false;
}

Influence Transformer::get_Influence() const
{
    return _Influence;
};
void Transformer::set_Influence(const Influence &influence)
{
    _Influence = influence;
};

void Transformer::set_Name(const std::string &Name)
{
    _Name = Name;
}
std::string Transformer::get_Name() const
{
    return _Name;
}


void Transformer::set_Level(const uint &Level)
{
    _Level = Level;
}
uint Transformer::get_Level() const
{
    return _Level;
}


void Transformer::set_MaxHealth(const uint &MaxHealth)
{
    _MaxHealth = MaxHealth;
}
uint Transformer::get_Maxhealth() const
{
    return _MaxHealth;
}


void Transformer::set_TempHealth(const uint &TempHealth)
{
    _TempHealth = TempHealth;
}
uint Transformer::get_TempHealth() const
{
    return _TempHealth;
}
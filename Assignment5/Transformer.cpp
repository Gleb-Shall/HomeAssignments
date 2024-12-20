/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/


#include "Transformer.h"

Transformer::Transformer():
    _Gun(new Gun("Defaut name", 0)),
    _Influence(0),
    _Name("Default name"),
    _Level(0),
    _MaxHealth(0),
    _TempHealth(0)
{};

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


bool Transformer::operator<(const Transformer& transformer)
{
    return get_TempHealth() < transformer.get_TempHealth();
}

bool Transformer::operator>(const Transformer& transformer)
{
    return  get_TempHealth() > transformer.get_TempHealth();
}

bool Transformer::operator==(const Transformer& transformer)
{
    return get_TempHealth() == transformer.get_TempHealth();
}


std::ostream& operator<<(std::ostream& os, const Transformer& transformer)
{
    os << "Transformer Name: " << transformer.get_Name() << ",\n";
    os << "Transformer Level: " << transformer.get_Level() << ",\n";
    os << "Transformer MaxHealth: " << transformer.get_Maxhealth() << ",\n";
    os << "Transformer TempHealth: " << transformer.get_TempHealth() << ",\n";
    os << "Transformer Gun: " << (*transformer.get_Gun());
    os << "transformer Influence: " << transformer.get_Influence() << "\n";
    return os;
}


void Transformer::transform()
{
    std::cout << "Transformer, transform" << std::endl;
}

void Transformer::ulta()
{
    std::cout << "Transformer, ulta" << std::endl;
}

void Transformer::openFire()
{
    std::cout << "Transformer, openFire"<<std::endl;
}

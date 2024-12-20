/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/


#include "Gun.h"


Gun::Gun(
    const std::string &Name,
    const uint &Damage):
    _Name(Name),
    _Damage(Damage) 
{}
Gun::~Gun() = default;


void Gun::set_Name(const std::string &Name)
{
    _Name = Name;
    return;
}
std::string Gun::get_Name() const
{
    return _Name;
}


void Gun::set_Damage(const uint &Damage)
{
    _Damage = Damage;
    return;
}
uint Gun::get_Damage() const
{
    return _Damage;
}

std::ostream& operator<<(std::ostream& os, const Gun& gun)
{
    os << "Gun name: " << gun.get_Name() << ", Gun Damage: " << gun.get_Damage() << ",\n";
    return os;
}

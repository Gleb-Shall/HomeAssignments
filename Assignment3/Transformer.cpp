/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#include "Gun.h"


Transformer::Transformer(std::string GunName, std::string TypeAmmo, uint Ammo, uint CountAmmoPerShoot, uint Damage,
                         std::string Name, uint Level, uint MaxHealth, uint TempHealth)
{
    _Gun = new Gun(GunName, TypeAmmo, Ammo, CountAmmoPerShoot, Damage);
    _Name = Name;
    _Level = Level;
    _MaxHealth = MaxHealth;
    _TempHealt = TempHealth;
}

bool Transformer::fire()
{
    if (_Gun -> get_Ammo() >= _Gun -> get_CountAmmoPerShoot() && Transformer::IsAlife())
    {
        Gun -> set_Ammo(_Gun -> get_Ammo() - _Gun -> get_CountAmmoPerShoot());
        return true;
    }
    return false;
}


bool Transformer::move()
{
    if (Transformer::IsAlife())
    {
        return true;
    }
    return false;
}


bool Transformer::IsAlife()
{
    if (Transformer::get_TempHealth() != 0)
    {
        return true;
    }
    return false;
}


Gun* Transformer::get_Gun()
{
    return _Gun;
}


void Transformer::set_Name(std::string Name)
{
    Name = Name;
    return;
}
std::string Transformer::get_Name()
{
    return _Name;
}


void Transformer::set_Level(uint Level)
{
    _Level = Level;
    return;
}
uint Transformer::get_Level()
{
    return _Level;
}


void Transformer::set_MaxHealth(uint MaxHealth)
{
    _MaxHealth = MaxHealth;
    return;
}
uint Transformer::get_Maxhealth()
{
    return _MaxHealth;
}


void Transformer::set_TempHealth(uint TempHealth);
{
    _TempHealth = TempHealth;
    return;
}
uint Transformer::get_TempHealth()
    return _TempHealth;
}


Transformer::~Transformer() = default{};

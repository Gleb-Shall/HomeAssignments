/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#include "Transformer.h"


Gun::Gun(std::string Name, std::string TypeAmmo, uint Ammo, uint CountAmmoPerShoot, uint Damage)
    : _Name(Name),
    _TypeAmmo(TypeAmmo),
    _Ammo(Ammo),
    _CountAmmoPerShoot(CountAmmoPerShoot),
    _Damage(Damage) {}


void Gun::set_Name(std::string Name)
{
    _Name = Name;
    return;
}
std::string Gun::get_Name()
{
    return _Name;
}


void Gun::set_TypeAmmo(std::string TypeAmmo)
{
    _TypeAmmo = TypeAmmo;
    return;
}
std::string Gun::get_TypeAmmo()
{
    return _TypeAmmo;
}


void Gun::set_Ammo(uint Ammo)
{
    _Ammo = Ammo;
    return;
}
uint Gun::get_Ammo()
{
    return _Ammo;
}


void Gun::set_CountAmmoPerShoot(uint CountAmmoPerShoot)
{
    _CountAmmoPerShoot = CountAmmoPerShoot;
    return;
}
uint Gun::get_CountAmmoPerShoot()
{
    return _CountAmmoPerShoot;
}


void Gun::set_Damage(uint Damage)
{
    _Damage = Damage;
    return;
}
uint Gun::get_Damage()
{
    return _Damage;
}


Gun::~Gun() = default;

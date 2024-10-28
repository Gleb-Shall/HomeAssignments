/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#include "Gun.h"


Transformer::Gun::Gun(std::string Name, std::string TypeAmmo, uint Ammo, uint CountAmmoPerShoot, uint Damage)
    : _Name(Name),
    _TypeAmmo(TypeAmmo),
    _Ammo(Ammo),
    _CountAmmoPerShoot(CountAmmoPerShoot),
    _Damage(Damage) {}


void Transformer::Gun::set_Name(std::string Name)
{
    _Name = Name;
    return;
}
std::string Transformer::Gun::get_Name()
{
    return _Name;
}


void Transformer::Gun::set_TypeAmmo(std::string TypeAmmo)
{
    _TypeAmmo = TypeAmmo;
    return;
}
std::string Transformer::Gun::get_TypeAmmo()
{
    return _TypeAmmo;
}


void Transformer::Gun::set_Ammo(std::uint Ammo)
{
    _Ammo = Ammo;
    return;
}
uint Transformer::Gun::get_Ammo()
{
    return _Ammo;
}


void Transformer::Gun::set_CountAmmoPerShoot(uint CountAmmoPerShoot)
{
    _CountAmmoPerShoot = CountAmmoPerShoot;
    return;
}
uint Transformer::Gun::get_CountAmmoPerShoot()
{
    return _CountAmmoPerShoot;
}


void Transformer::Gun::set_Damage(uint Damage)
{
    _Damage = Damage;
    return;
}
uint Transformer::Gun::get_Damage()
{
    return _Damage;
}


Transformer::Gun::~Gun()
{
    delete[] _Name;
    delete[] _TypeAmmo;
    delete[] _Ammo;
    delete[] _CountAmmoPerShoot;
    delete[] _Damage;
}

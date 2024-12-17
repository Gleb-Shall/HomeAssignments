/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#ifndef TRANSFORMER_H
#define TRANSORMER_H

#include "Gun.h"


class Transformer
{
public:
    Transformer(std::string GunName, std::string TypeAmmo, uint Ammo, uint CountAmmoPerShoot, uint Damage,
    std::string Name, uint Level, uint MaxHealth, uint TempHealth);

    bool fire();
    bool move();
    bool IsAlife();

    Gun* get_Gun();

    void set_Name(std::string Name);
    std::string get_Name();

    void set_Level(uint Level);
    uint get_Level();

    void set_MaxHealth(uint MaxHealth);
    uint get_Maxhealth();

    void set_TempHealth(uint TempHealth);
    uint get_TempHealth();

    ~Transformer();
private:
    Gun* _Gun;
    std::string _Name;
    uint _Level;
    uint _MaxHealth;
    uint _TempHealth;
};

#endif

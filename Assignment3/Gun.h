/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#ifndef GUN_H
#define GUN_H

#include <string>


class Gun
{
public:
    Gun(std::string Name, std::string TypeAmmo, uint Ammo, uint CountAmmoPerShoot, uint Damage);

    void set_Name(std::string Name);
    std::string get_Name();

    void set_TypeAmmo(std::string TypeAmmo);
    std::string get_TypeAmmo();

    void set_Ammo(uint Ammo);
    uint get_Ammo();

    void set_CountAmmoPerShoot(uint CountAmmoPerShoot);
    uint get_CountAmmoPerShoot();

    void set_Damage(uint Damage);
    uint get_Damage();

    ~Gun();
private:
    std::string _Name;
    std::string _TypeAmmo;
    uint _Ammo;
    uint _CountAmmoPerShoot;
    uint _Damage;
};

#endif

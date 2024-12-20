/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 5
*/


#ifndef GUN_H
#define GUN_H

#include <string>
#include <iostream>


class Gun
{
private:
    std::string _Name;
    uint _Damage;
public:
    Gun(
        const std::string &Name,
        const uint &Damage);
    
    ~Gun();
    
    void set_Name(const std::string &Name);
    std::string get_Name() const;

    void set_Damage(const uint &Damage);
    uint get_Damage() const;
};

std::ostream& operator<<(std::ostream& os, const Gun& gun);

#endif

/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/


#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "Gun.h"
#include "Influence.h"

class Transformer
{
private:
    Gun* _Gun;
    Influence _Influence;
    std::string _Name;
    uint _Level;
    uint _MaxHealth;
    uint _TempHealth;
public:
    Transformer();
    Transformer(
        Gun* gun,
        const int &Influence_on_robots,
        const std::string &Name,
        const uint &Level,
        const uint &MaxHealth,
        const uint &TempHealth
        );

    ~Transformer();

    bool move();
    bool IsAlife();

    Gun* get_Gun() const;
    void set_Gun(Gun* gun);
    bool fire();

    Influence get_Influence() const;
    void set_Influence(const Influence &influence);

    void set_Name(const std::string &Name);
    std::string get_Name() const;

    void set_Level(const uint &Level);
    uint get_Level() const;

    void set_MaxHealth(const uint &MaxHealth);
    uint get_Maxhealth() const;

    void set_TempHealth(const uint &TempHealth);
    uint get_TempHealth() const;
    
    bool operator<(const Transformer& transformer);
    bool operator>(const Transformer& transformer);
    bool operator==(const Transformer& transformer);
};

std::ostream& operator<<(std::ostream& os, const Transformer& transformer);

#endif

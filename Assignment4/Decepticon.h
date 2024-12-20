/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/


#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon:public Transformer{
private:
    std::string _Commander;
    int Amount_of_evil;

public:
    Decepticon();
    Decepticon(
        Gun* gun,
        const int &Influence_on_robots,
        const std::string &Name,
        const uint &Level,
        const uint &MaxHealth,
        const uint &TempHealth,
        const std::string &Commander,
        const int &amount_of_evil
    );
    ~Decepticon();

    std::string get_Commander() const;
    void set_Commander(const std::string &Commander);

    int get_amount_of_evil() const;
    void set_amount_of_evil(const int &amount_of_evil);
        
    void call_Comander();
};

std::ostream& operator<<(std::ostream& os, const Decepticon& decepticon);

#endif

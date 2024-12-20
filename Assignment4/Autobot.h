/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/


#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"

class Autobot:public Transformer{
private:
    std::string _Commander;
    int Amount_of_kindness;

public:
    Autobot(
        Gun* gun,
        const int &Influence_on_robots,
        const std::string &Name,
        const uint &Level,
        const uint &MaxHealth,
        const uint &TempHealth,
        const std::string &Commander,
        const int &amount_of_kindness
    );
    ~Autobot();

    std::string get_Commander() const;
    void set_Commander(const std::string &Commander);

    int get_amount_of_kindness() const;
    void set_amount_of_kindness(const int &amount_of_kindness);
        
    void call_Comander();
};

std::ostream& operator<<(std::ostream& os, const Autobot& autobot);

#endif

/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/


#ifndef MINICON_H
#define MINICON_H

#include "Transformer.h"

class Minicon:public Transformer{
private:
    std::string _Master;
    int Number_of_important_things_to_do;

public:
    Minicon(
        Gun* gun,
        const int &Influence_on_robots,
        const std::string &Name,
        const uint &Level,
        const uint &MaxHealth,
        const uint &TempHealth,
        const std::string &Master,
        const int &number_of_important_things_to_do
    );
    ~Minicon();

    std::string get_Master() const;
    void set_Master(const std::string &Master);

    int get_number_of_important_things_to_do() const;
    void set_number_of_important_things_to_do(const int &number_of_important_things_to_do);
    
    void call_Master();
};

std::ostream& operator<<(std::ostream& os, const Minicon& minicon);

#endif

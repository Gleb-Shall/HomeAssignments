/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 5
*/


#ifndef INFLUENCE_H
#define INFLUENCE_H


#include <iostream>

class Influence
{
private:
    int _Power;
public:
    Influence(const int &Power);
    ~Influence();
    
    void set_Power(const int &Power);
    int get_Power() const;
};

std::ostream& operator<<(std::ostream& os, const Influence& influence);

#endif

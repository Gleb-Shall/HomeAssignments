/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#include "Influence.h"

Influence::Influence(const int &Power): _Power(Power){}

Influence::~Influence() = default;

void Influence::set_Power(const int &Power)
{
    _Power = Power;
}

int Influence::get_Power() const
{
    return _Power;
}
/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 5
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

std::ostream& operator<<(std::ostream& os, const Influence& influence)
{
    os << "Influence.power: " << influence.get_Power() << ",\n";
    return os;
}

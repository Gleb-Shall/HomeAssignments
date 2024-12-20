/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#ifndef INFLUENCE_H
#define INFLUENCE_H


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

#endif
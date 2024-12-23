/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 6
*/


#ifndef TRANSFORMER_H
#define TRANSFORMER_H


#include <vector>


// General template
template <typename T1, typename T2>
class Transformer {
private:
    int number;
    std::vector<float> vec;
    T1 instance;

public:
    Transformer(int numberp, const std::vector<float>& vec, const T1& obj);
    bool foo();
};

// Partial specialization for <int, T>
template <typename T>
class Transformer<int, T> {
private:
    int number;
    std::vector<float> vec;

public:
    Transformer(int numberp, const std::vector<float>& vecp, const T& obj);
    bool foo();
};

// Partial specialization for <double, T>
template <typename T>
class Transformer<double, T> {
private:
    int number;
    std::vector<float> vec;

public:
    Transformer(int numberp, const std::vector<float>& vecp, const T& obj);
    bool foo();
};

#endif
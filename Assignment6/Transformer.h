/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 6
*/


#ifndef TRANSFORMER_H
#define TRANSFORMER_H


#include <vector>
#include <iostream>


template <typename T1, typename T2>
class Transformer {
private:
    int number;
    std::vector<float> vec;
    T1 instance;

public:
    Transformer(int numberp, const std::vector<float>& vec, const T1& obj)
        : number(numberp), vec(vec), instance(obj) {}

    bool foo() {
        return instance.bar(number, vec);
    }
};

// Partial specialization
template <typename T>
class Transformer<int, T> {
private:
    int number;
    std::vector<float> vec;

public:
    Transformer(int numberp, const std::vector<float>& vecp, const T& obj)
        : number(numberp), vec(vecp) {}

    bool foo() {
        return true;
    }
};

// Partial specialization
template <typename T>
class Transformer<double, T> {
private:
    int number;
    std::vector<float> vec;

public:
    Transformer(int numberp, const std::vector<float>& vecp, const T& obj)
        : number(numberp), vec(vecp) {}

    bool foo() {
        return false;
    }
};

#endif

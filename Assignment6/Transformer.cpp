/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 6
*/


#include "Transformer.h"


// General template implementation
template <typename T1, typename T2>
Transformer<T1, T2>::Transformer(int numberp, const std::vector<float>& vec, const T1& obj)
    : number(numberp), vec(vec), instance(obj) {}

template <typename T1, typename T2>
bool Transformer<T1, T2>::foo() {
    return instance.bar(number, vec);
}

// Partial specialization for <int, T>
template <typename T>
Transformer<int, T>::Transformer(int numberp, const std::vector<float>& vecp, const T& obj)
    : number(numberp), vec(vecp) {}

template <typename T>
bool Transformer<int, T>::foo() {
    return true;
}

// Partial specialization for <double, T>
template <typename T>
Transformer<double, T>::Transformer(int numberp, const std::vector<float>& vecp, const T& obj)
    : number(numberp), vec(vecp) {}

template <typename T>
bool Transformer<double, T>::foo() {
    return false;
}

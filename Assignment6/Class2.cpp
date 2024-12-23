/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 6
*/


#include "Class2.h"


bool Class2::bar(int num, const std::vector<float>& vec) {
    return !vec.empty();
}

int Class2::c_2_1() {
    std::cout << "c_2_1\n";
    return 2;
}

float Class2::c_2_2() {
    std::cout << "c_2_2\n";
    return 0.2f;
}

void Class2::c_2_3() {
    std::cout << "c_2_3\n";
}
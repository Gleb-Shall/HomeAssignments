/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 6
*/


#include "Class1.h"


bool Class1::bar(int num, const std::vector<float>& vec) {
    return num > 0;
}

int Class1::c_1_1() {
    std::cout << "c_1_1\n";
    return 1;
}

float Class1::c_1_2() {
    std::cout << "c_1_2\n";
    return 0.1f;
}

void Class1::c_1_3() {
    std::cout << "c_1_3\n";
}
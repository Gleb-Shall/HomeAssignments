/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 6
*/


#include "Class3.h"


bool Class3::bar(int num, const std::vector<float>& vec) {
    return num == -static_cast<int>(vec.size());
}

int Class3::c_3_1() {
    std::cout << "c_3_1\n";
    return 3;
}

float Class3::c_3_2() {
    std::cout << "c_3_2\n";
    return 0.3f;
}

void Class3::c_3_3() {
    std::cout << "c_3_3\n";
}
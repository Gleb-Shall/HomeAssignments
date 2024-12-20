/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 6
*/


#include <gtest/gtest.h>
#include <iostream>
#include <vector>


// General template
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


class Class1 {
public:
    bool bar(int num, const std::vector<float>& vec) {
        return num > 0;
    }

    int c_1_1() {
        std::cout << "c_1_1\n";
        return 1;
    }

    float c_1_2() {
        std::cout << "c_1_2\n";
        return 0.1f;
    }

    void c_1_3() {
        std::cout << "c_1_3\n";
    }
};

class Class2 {
public:
    bool bar(int num, const std::vector<float>& vec) {
        return !vec.empty();
    }

    int c_2_1() {
        std::cout << "c_2_1\n";
        return 2;
    }

    float c_2_2() {
        std::cout << "c_2_2\n";
        return 0.2f;
    }

    void c_2_3() {
        std::cout << "c_2_3\n";
    }
};

class Class3 {
public:
    bool bar(int num, const std::vector<float>& vec) {
        return num == -static_cast<int>(vec.size());
    }

    int c_3_1() {
        std::cout << "c_3_1\n";
        return 3;
    }

    float c_3_2() {
        std::cout << "c_3_2\n";
        return 0.3f;
    }

    void c_3_3() {
        std::cout << "c_3_3\n";
    }
};

int main(int arg, char **argv)
{
    ::testing::InitGoogleTest(&arg, argv);
    return RUN_ALL_TESTS();
}

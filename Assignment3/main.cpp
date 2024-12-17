/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 3
*/


#include "Transformer.h"
#include "Gun.h"
#include <iostream>


int main(int arg, char *argv[])
{
    Transformer* Robot = new Transformer("Booba", "Bullet", 120, 50, 30,
                                        "Zelb", 1, 40, 40);
    std::cout << Robot -> get_Name() << "\n" << Robot -> get_Level() << "\n" << Robot -> get_Gun() -> get_Ammo() << "\n";
    Robot -> fire();
    Robot -> fire();
    Robot -> fire();
    std::cout << Robot -> get_Name() << "\n" << Robot -> get_Level() << "\n" << Robot -> get_Gun() -> get_Ammo() << "\n";
}

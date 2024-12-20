/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Lab1
*/


#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "WorkWithBMP.h"


void test()
{

    std::string path = "Mandrill.bmp";
    Image image = Image(512, 512, path);
    std::cout<<512*512<<" byte will be ocupied by img";
    std::vector<unsigned char> vector = image.readToVector(path, 512*512);
    /*
    for(int i = 0; i<= 10; i++)
    {
        std::cout<<vector[i]<<std::endl;
    }
    */
    //image.writeToFile("new.bmp",vector);
    //image.writeToRaw("new.raw", vector);
    image.writeToRaw("cwrotated.bmp",image.clockwiseRotate(vector));
    image.writeToRaw("ccwrotated.bmp", image.counterClockwiseRotate(vector));
    image.saveAsGaussianImage(image.counterClockwiseRotate(vector),5);
}

int main()
{
    test();
}

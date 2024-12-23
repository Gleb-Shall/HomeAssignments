/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Lab1
*/

#include <iostream>
#include "WorkWithBMP.h"

int main() {
    try {
        std::string inputPath = "Mandrill.bmp";
        std::string outputPathRotated = "Mandrill_rotated.bmp";
        std::string outputPathFiltered = "Mandrill_filtered.bmp";

        Image image(inputPath);

        // Read BMP data
        auto data = image.readToVector(inputPath);

        // Rotate and save
        image.rotate90Clockwise(data);
        image.writeFromVector(outputPathRotated, data);
        std::cout << "Rotated image saved to " << outputPathRotated << std::endl;

        // Apply Gaussian filter and save
        image.applyGaussianFilter(data);
        image.writeFromVector(outputPathFiltered, data);
        std::cout << "Filtered image saved to " << outputPathFiltered << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

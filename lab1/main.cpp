/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Lab1
*/

#include <iostream>
#include "WorkWithBMP.h"

int main() {
    try {
        std::string inputPath = "1718889054_sample_640×426.bmp";

        std::string outputPathRotatedClockwise = "Mandrill_rotated_clockwise.bmp";
        std::string outputPathFilteredClockwise = "Mandrill_filtered_clockwise.bmp";

        std::string outputPathRotatedCounterClockwise = "Mandrill_rotated_counter_clockwise.bmp";
        std::string outputPathFilteredCounterClockwise = "Mandrill_filtered_counter_clockwise.bmp";


        Image image(inputPath);

        // Read BMP data
        auto dataClockwise = image.readToVector(inputPath);
        auto dataCounterClockwise = image.readToVector(inputPath);

        // Rotate 90 Clockwise and save
        image.rotate90Clockwise(dataClockwise);
        image.writeFromVector(outputPathRotatedClockwise, dataClockwise);
        std::cout << "Rotated image saved to " << outputPathRotatedClockwise << std::endl;

        // Apply Gaussian filter and save
        image.applyGaussianFilter(dataClockwise);
        image.writeFromVector(outputPathFilteredClockwise, dataClockwise);
        std::cout << "Filtered image saved to " << outputPathFilteredClockwise << std::endl;

        // Rotate 90 Counter Clockwise and save
        image.rotate90CounterClockwise(dataCounterClockwise);
        image.writeFromVector(outputPathRotatedCounterClockwise, dataCounterClockwise);
        std::cout << "Rotated image saved to " << outputPathRotatedCounterClockwise << std::endl;

        // Apply Gaussian filter and save
        image.applyGaussianFilter(dataCounterClockwise);
        image.writeFromVector(outputPathFilteredCounterClockwise, dataCounterClockwise);
        std::cout << "Filtered image saved to " << outputPathFilteredCounterClockwise << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

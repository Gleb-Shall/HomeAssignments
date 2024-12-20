/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Lab1
*/

#include <iostream>
#include <vector>
#include <string>
#include "WorkWithBMP.h"

int main() {
    try {
        // Input and output paths
        std::string inputPath = "Mandrill.bmp";
        std::string outputPathRotated = "Mandrill_rotated.bmp";
        std::string outputPathFiltered = "Mandrill_filtered.bmp";

        // Initialize image
        Image image(512, 512, inputPath);

        // Read BMP data into vector
        std::vector<unsigned char> data = image.readToVector(inputPath, 512 * 512);

        // Rotate image by 90 degrees clockwise
        image.rotate90Clockwise(data);
        image.writeFromVector(outputPathRotated, data);
        std::cout << "Image rotated and saved to " << outputPathRotated << "\\n";

        // Apply Gaussian filter
        image.applyGaussianFilter(data);
        image.writeFromVector(outputPathFiltered, data);
        std::cout << "Gaussian filter applied and saved to " << outputPathFiltered << "\\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

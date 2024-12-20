/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Lab1
*/


#ifndef WORKWITHBMP_H
#define WORKWITHBMP_H


#include<string>
#include<iostream>
#include<utility>
#include<fstream>
#include<cmath>
#include<vector>

struct Image
{
public:
    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    unsigned char fileHeader[14];
    unsigned char informationHeader[40];
    int width;
    int height;
    std::string path;

    // Constructor to initialize headers
    Image(int w, int h, const std::string& p) : width(w), height(h), path(p) {}

    // Read BMP to vector
    std::vector<unsigned char> readToVector(const std::string& filePath, size_t size) {
        std::ifstream file(filePath, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Cannot open file: " + filePath);
        }

        std::vector<unsigned char> buffer(size);
        file.seekg(fileHeaderSize + informationHeaderSize, std::ios::beg);
        file.read(reinterpret_cast<char*>(buffer.data()), size);
        file.close();

        return buffer;
    }

    // Write BMP from vector
    void writeFromVector(const std::string& outputPath, const std::vector<unsigned char>& data) {
        std::ofstream file(outputPath, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Cannot open file: " + outputPath);
        }

        file.write(reinterpret_cast<const char*>(fileHeader), fileHeaderSize);
        file.write(reinterpret_cast<const char*>(informationHeader), informationHeaderSize);
        file.write(reinterpret_cast<const char*>(data.data()), data.size());
        file.close();
    }

    // Rotate image 90 degrees clockwise
    void rotate90Clockwise(std::vector<unsigned char>& data) {
        std::vector<unsigned char> rotated(height * width);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                rotated[x * height + (height - y - 1)] = data[y * width + x];
            }
        }
        std::swap(width, height);
        data = std::move(rotated);
    }

    // Apply Gaussian filter
    void applyGaussianFilter(std::vector<unsigned char>& data) {
        const int kernelSize = 3;
        const float kernel[kernelSize][kernelSize] = {
            {1.0f / 16, 2.0f / 16, 1.0f / 16},
            {2.0f / 16, 4.0f / 16, 2.0f / 16},
            {1.0f / 16, 2.0f / 16, 1.0f / 16}
        };

        std::vector<unsigned char> filtered(height * width);
        for (int y = 1; y < height - 1; ++y) {
            for (int x = 1; x < width - 1; ++x) {
                float sum = 0.0f;
                for (int ky = 0; ky < kernelSize; ++ky) {
                    for (int kx = 0; kx < kernelSize; ++kx) {
                        int px = x + kx - 1;
                        int py = y + ky - 1;
                        sum += kernel[ky][kx] * data[py * width + px];
                    }
                }
                filtered[y * width + x] = static_cast<unsigned char>(sum);
            }
        }
        data = std::move(filtered);
    }
};

#endif

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
    unsigned char fileHeader[14] = {0};
    unsigned char informationHeader[40] = {0};
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

        // Read file and information headers
        file.read(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
        file.read(reinterpret_cast<char*>(informationHeader), informationHeaderSize);

        // Read pixel data
        std::vector<unsigned char> buffer(size);
        file.read(reinterpret_cast<char*>(buffer.data()), size);
        file.close();

        return buffer;
    }

    // Write BMP from vector
    void writeFromVector(const std::string& outputPath, const std::vector<unsigned char>& data) {
        // Update file header size
        int rowSize = (width * 3 + 3) & (~3); // Row size must be a multiple of 4 bytes
        int dataSize = rowSize * height;
        int fileSize = fileHeaderSize + informationHeaderSize + dataSize;

        // Update file header
        fileHeader[2] = fileSize & 0xFF;
        fileHeader[3] = (fileSize >> 8) & 0xFF;
        fileHeader[4] = (fileSize >> 16) & 0xFF;
        fileHeader[5] = (fileSize >> 24) & 0xFF;

        // Update information header
        informationHeader[4] = width & 0xFF;
        informationHeader[5] = (width >> 8) & 0xFF;
        informationHeader[6] = (width >> 16) & 0xFF;
        informationHeader[7] = (width >> 24) & 0xFF;

        informationHeader[8] = height & 0xFF;
        informationHeader[9] = (height >> 8) & 0xFF;
        informationHeader[10] = (height >> 16) & 0xFF;
        informationHeader[11] = (height >> 24) & 0xFF;

        // Write data to output file
        std::ofstream file(outputPath, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Cannot open file: " + outputPath);
        }

        file.write(reinterpret_cast<const char*>(fileHeader), fileHeaderSize);
        file.write(reinterpret_cast<const char*>(informationHeader), informationHeaderSize);

        // Write pixel data row by row to ensure proper padding
        int padding = rowSize - width * 3;
        for (int y = 0; y < height; ++y) {
            file.write(reinterpret_cast<const char*>(&data[y * width * 3]), width * 3);
            file.write("\0\0\0", padding); // Write padding bytes
        }

        file.close();
    }

    // Rotate image 90 degrees clockwise
    void rotate90Clockwise(std::vector<unsigned char>& data) {
        std::vector<unsigned char> rotated(height * width * 3);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                for (int c = 0; c < 3; ++c) { // Process each color channel (RGB)
                    rotated[(x * height + (height - y - 1)) * 3 + c] = data[(y * width + x) * 3 + c];
                }
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

        std::vector<unsigned char> filtered(height * width * 3);
        for (int y = 1; y < height - 1; ++y) {
            for (int x = 1; x < width - 1; ++x) {
                for (int c = 0; c < 3; ++c) { // Process each color channel (RGB)
                    float sum = 0.0f;
                    for (int ky = 0; ky < kernelSize; ++ky) {
                        for (int kx = 0; kx < kernelSize; ++kx) {
                            int px = x + kx - 1;
                            int py = y + ky - 1;
                            sum += kernel[ky][kx] * data[(py * width + px) * 3 + c];
                        }
                    }
                    filtered[(y * width + x) * 3 + c] = static_cast<unsigned char>(sum);
                }
            }
        }
        data = std::move(filtered);
    }
};

#endif
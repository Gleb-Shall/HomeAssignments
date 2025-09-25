#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

void analyzeBMPDetailed(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Cannot open file: " << filename << std::endl;
        return;
    }
    
    // Read file header
    unsigned char fileHeader[14];
    file.read(reinterpret_cast<char*>(fileHeader), 14);
    
    // Read info header
    unsigned char infoHeader[40];
    file.read(reinterpret_cast<char*>(infoHeader), 40);
    
    // Extract information
    int fileSize = *reinterpret_cast<int*>(&fileHeader[2]);
    int dataOffset = *reinterpret_cast<int*>(&fileHeader[10]);
    int width = *reinterpret_cast<int*>(&infoHeader[4]);
    int height = *reinterpret_cast<int*>(&infoHeader[8]);
    int bitsPerPixel = *reinterpret_cast<short*>(&infoHeader[14]);
    int compression = *reinterpret_cast<int*>(&infoHeader[16]);
    int imageSize = *reinterpret_cast<int*>(&infoHeader[20]);
    int xPixelsPerMeter = *reinterpret_cast<int*>(&infoHeader[24]);
    int yPixelsPerMeter = *reinterpret_cast<int*>(&infoHeader[28]);
    int colorsUsed = *reinterpret_cast<int*>(&infoHeader[32]);
    int importantColors = *reinterpret_cast<int*>(&infoHeader[36]);
    
    std::cout << "=== " << filename << " ===" << std::endl;
    std::cout << "File size: " << fileSize << " bytes" << std::endl;
    std::cout << "Data offset: " << dataOffset << " bytes" << std::endl;
    std::cout << "Width: " << width << " pixels" << std::endl;
    std::cout << "Height: " << height << " pixels" << std::endl;
    std::cout << "Bits per pixel: " << bitsPerPixel << std::endl;
    std::cout << "Compression: " << compression << std::endl;
    std::cout << "Image size: " << imageSize << " bytes" << std::endl;
    std::cout << "X pixels per meter: " << xPixelsPerMeter << std::endl;
    std::cout << "Y pixels per meter: " << yPixelsPerMeter << std::endl;
    std::cout << "Colors used: " << colorsUsed << std::endl;
    std::cout << "Important colors: " << importantColors << std::endl;
    
    // Check if there's a color palette
    int headerSize = 14 + 40;
    int paletteSize = dataOffset - headerSize;
    std::cout << "Palette size: " << paletteSize << " bytes" << std::endl;
    
    if (paletteSize > 0) {
        std::cout << "File has color palette!" << std::endl;
    }
    
    std::cout << std::endl;
    file.close();
}

int main() {
    analyzeBMPDetailed("example.bmp");
    analyzeBMPDetailed("example_rotated_clockwise.bmp");
    return 0;
}

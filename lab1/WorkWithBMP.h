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
    Image(
        int width,
        int height,
        std::string path):
        width(width),
        height(height), 
        path(path)
    {
        const int imageSize = width * height + fileHeaderSize + informationHeaderSize;

        // File Header
        fileHeader[0] = 'B';
        fileHeader[1] = 'M';
        fileHeader[2] = imageSize;
        fileHeader[3] = imageSize >> 8;
        fileHeader[4] = imageSize >> 16;
        fileHeader[5] = imageSize >> 24;
        fileHeader[6] = 0;
        fileHeader[7] = 0;
        fileHeader[8] = 0;
        fileHeader[9] = 0;
        fileHeader[10] = fileHeaderSize + informationHeaderSize;
        fileHeader[11] = 0;
        fileHeader[12] = 0;
        fileHeader[13] = 0;

        // Information Header
        informationHeader[0] = informationHeaderSize;
        informationHeader[1] = 0;
        informationHeader[2] = 0;
        informationHeader[3] = 0;
        informationHeader[4] = width;
        informationHeader[5] = width >> 8;
        informationHeader[6] = width >> 16;
        informationHeader[7] = width >> 24;
        informationHeader[8] = height;
        informationHeader[9] = height >> 8;
        informationHeader[10] = height >> 16;
        informationHeader[11] = height >> 24;
        informationHeader[12] = 1; // Planes
        informationHeader[13] = 0;
        informationHeader[14] = 8; // Bits per pixel
        informationHeader[15] = 0;
        informationHeader[16] = 0; // Compression
        informationHeader[17] = 0;
        informationHeader[18] = 0;
        informationHeader[19] = 0;
        informationHeader[20] = 0; // Image size
        informationHeader[21] = 0;
        informationHeader[22] = 0;
        informationHeader[23] = 0;
        informationHeader[24] = 0; // X pixels per meter
        informationHeader[25] = 0;
        informationHeader[26] = 0;
        informationHeader[27] = 0;
        informationHeader[28] = 0; // Y pixels per meter
        informationHeader[29] = 0;
        informationHeader[30] = 0;
        informationHeader[31] = 0;
        informationHeader[32] = 0; // Colors in color table
        informationHeader[33] = 0;
        informationHeader[34] = 0;
        informationHeader[35] = 0;
        informationHeader[36] = 0; // Important color count
        informationHeader[37] = 0;
        informationHeader[38] = 0;
        informationHeader[39] = 0;
    }


    // Method to save pixel data to BMP
    void writeToFile(const std::string& filename, const std::vector<unsigned char>& pixelData)
    {
        std::ofstream file(filename, std::ios::binary);
        if (!file)
        {
            throw std::runtime_error("Failed to open file for writing: " + filename);
        }

        // Write headers
        file.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
        file.write(reinterpret_cast<char*>(informationHeader), informationHeaderSize);

        // Calculate padding size (row size must be a multiple of 4 bytes)
        const int rowSize = round4(width); // Align to nearest multiple of 4
        const int padding = rowSize - width;

        // Padding data
        unsigned char paddingBytes[3] = {0, 0, 0}; // Up to 3 bytes of padding per row

        // Write pixel data (BMP stores pixel rows bottom-to-top)
        for (int y = 0; y < height; ++y)
        {
            // Write the row of pixel data
            file.write(reinterpret_cast<const char*>(&pixelData[y * width]), width);

            // Write padding bytes
            if (padding > 0)
            {
                file.write(reinterpret_cast<const char*>(paddingBytes), padding);
            }
        }

        file.close();
    }

    int round4(int x)
    {
        return x%4 == 0 ? x:x - x%4 + 4;
    }

    void blueAndRedChanging(std::vector<unsigned char>& pixel)
    {
        size_t size = pixel.size();
        for( size_t i = 0; i < size; i+=3)
        {
            std::swap(pixel[i], pixel[i+2]);
        }
    }

    //raw to array
    std::vector<unsigned char> readToVector(std::string path, int size)
    {
        // Open the file in binary mode
        std::ifstream file(path, std::ios::binary);

        //allocating vector
        std::vector<unsigned char> output (size);

        //write into file
        if (!file.read(reinterpret_cast<char*>(output.data()), size))
        {
            throw std::runtime_error("Error reading file: " + path);
        }
        //blueAndRedChanging(output);
        return output;

    }

    void writeToRaw(std::string filename, std::vector<unsigned char> vector)
    {
        std::ofstream file(filename, std::ios::binary);
        file.write(reinterpret_cast<const char*>(vector.data()), vector.size());
        file.close();
    }

    std::vector<std::vector<unsigned char> > oneDimToTwoDim(std::vector <unsigned char> one_dim)
    {
        std::vector<std::vector<unsigned char> > two_dim(height, std::vector<unsigned char>(width));
        for (int y = 0; y<height; y++)
        {
            for (int x = 0; x<width; x++)
            {
                two_dim[y][x] = one_dim[y * width + x];
            }
        }
        return two_dim;
    }

    std::vector<unsigned char> twoDimToOneDim(std::vector<std::vector<unsigned char> > two_dim)
    {
        std::vector<unsigned char> one_dim(width*height);
        for (int x = 0; x<width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                one_dim[x + y * width] = two_dim[y][x];
            }
        }
        return one_dim;
    }

    std::vector<unsigned char> clockwiseRotate(std::vector<unsigned char> img)
    {
        auto img_2d = oneDimToTwoDim(img);
        std::vector<std::vector<unsigned char> > rotated_img(width, std::vector<unsigned char>(height));

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                rotated_img[x][height - y - 1] = img_2d[y][x];
            }
        }

        return twoDimToOneDim(rotated_img);
    }


    std::vector<unsigned char> counterClockwiseRotate(std::vector<unsigned char> img)
    {
        return clockwiseRotate(clockwiseRotate(clockwiseRotate(img)));
    }

   std::pair<std::vector<std::vector<float>>, int> makeKernel(int sigma)
    {
        int kernel_size = (sigma * 6) + 1;  // Kernel size based on sigma
        int kernel_length = kernel_size;    // Kernel is square
        std::vector<std::vector<float>> kernel(kernel_length, std::vector<float>(kernel_length));

        float sum = 0.0f;  // For normalization

        // Compute the kernel
        int radius = kernel_length / 2;
        for (int y = -radius; y <= radius; y++)
        {
            for (int x = -radius; x <= radius; x++)
            {
                // Calculate Gaussian value
                kernel[y + radius][x + radius] = (1.0f / (2.0f * 3.14f * sigma * sigma)) * std::exp(-((x * x + y * y) / (2.0f * sigma * sigma)));
                sum += kernel[y + radius][x + radius];
            }
        }

        // Normalize the kernel so that the sum is 1
        for (int y = 0; y < kernel_length; y++)
        {
            for (int x = 0; x < kernel_length; x++)
            {
                kernel[y][x] /= sum;
            }
        }

        return {kernel, kernel_length};
    }

    template<typename T>
    T clamp(T value, T min_value, T max_value)
    {
        if (value < min_value)
        {
            return min_value;
        }
        else if (value > max_value)
        {
            return max_value;
        }
        else
        {
            return value;
        }
    }

    void saveAsGaussianImage(std::vector<unsigned char> img, int sigma)
    {
        auto img_2d = oneDimToTwoDim(img);

        auto kernel_pair = makeKernel(sigma);
        auto kernel = kernel_pair.first;
        int kernel_length = kernel_pair.second;
        int kernel_radius = kernel_length / 2;

        // Create an output image (initialize with zeros)
        std::vector<std::vector<unsigned char> > blurred_img(height, std::vector<unsigned char>(width, 0));

        // Convolve the image with the kernel
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                float sum = 0.0f;

                for (int ky = -kernel_radius; ky <= kernel_radius; ky++)
                {
                    for (int kx = -kernel_radius; kx <= kernel_radius; kx++)
                    {
                        // Boundary handling using manual clamping
                        int ny = y + ky;
                        int nx = x + kx;

                        if (ny < 0) ny = 0;
                        if (ny >= height) ny = height - 1;
                        if (nx < 0) nx = 0;
                        if (nx >= width) nx = width - 1;

                        sum += img_2d[ny][nx] * kernel[ky + kernel_radius][kx + kernel_radius];
                    }
                }

                // Store the clamped result
                blurred_img[y][x] = static_cast<unsigned char>(clamp(std::round(sum), 0.0f, 255.0f));
            }
        }

        // Convert the blurred 2D image back to 1D
        auto blurred_img_1d = twoDimToOneDim(blurred_img);

        // Save the output as a new RAW file
        writeToRaw("gaussian_blurred.raw", blurred_img_1d);
    }


};
#endif

#include "Utils.h"
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Initialize random seed
static bool randomInitialized = false;

void Utils::InitializeRandom() {
    if (!randomInitialized) {
        srand(static_cast<unsigned int>(time(nullptr)));
        randomInitialized = true;
    }
}

int Utils::RandomInt(int min, int max) {
    InitializeRandom();
    return min + rand() % (max - min + 1);
}

std::vector<std::string> Utils::Split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

std::string Utils::ToLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string Utils::Trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

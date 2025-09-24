#pragma once
#include <string>
#include <vector>

class Utils {
public:
    static int RandomInt(int min, int max);
    static std::vector<std::string> Split(const std::string& str, char delimiter);
    static std::string ToLower(const std::string& str);
    static std::string Trim(const std::string& str);
private:
    static void InitializeRandom();
};
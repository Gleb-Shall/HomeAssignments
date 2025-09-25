/**
 * @file Utils.h
 * @brief Utility functions class
 * @author Gleb Shikunov
 */

#pragma once
#include <string>
#include <vector>

/**
 * @class Utils
 * @brief Collection of static utility functions
 * 
 * This class provides various utility functions for string manipulation,
 * random number generation, and other common operations.
 */
class Utils {
public:
    /**
     * @brief Generate random integer
     * @param min Minimum value (inclusive)
     * @param max Maximum value (inclusive)
     * @return Random integer between min and max
     */
    static int RandomInt(int min, int max);
    
    /**
     * @brief Split string by delimiter
     * @param str String to split
     * @param delimiter Character to split on
     * @return Vector of split strings
     */
    static std::vector<std::string> Split(const std::string& str, char delimiter);
    
    /**
     * @brief Convert string to lowercase
     * @param str String to convert
     * @return Lowercase version of the string
     */
    static std::string ToLower(const std::string& str);
    
    /**
     * @brief Trim whitespace from string
     * @param str String to trim
     * @return String with leading and trailing whitespace removed
     */
    static std::string Trim(const std::string& str);

private:
    /**
     * @brief Initialize random number generator
     * 
     * Sets up the random number generator with current time seed.
     */
    static void InitializeRandom();
};
/**
 * @file Logger.h
 * @brief Logging system class
 * @author Gleb Shikunov
 */

#pragma once
#include <string>
#include <vector>

/**
 * @class Logger
 * @brief Logging system for game events and debugging
 * 
 * This class provides a comprehensive logging system with different
 * log levels and the ability to save logs to files.
 */
class Logger {
public:
    /**
     * @enum LogLevel
     * @brief Different levels of logging
     */
    enum LogLevel { DEBUG, INFO, WARNING, ERROR };
    
    /**
     * @brief Default constructor
     * 
     * Initializes logger with default log level.
     */
    Logger();
    
    /**
     * @brief Log a message
     * @param msg Message to log
     * 
     * Logs a message with the current log level.
     */
    void Log(std::string msg);
    
    /**
     * @brief Log an error message
     * @param msg Error message to log
     * 
     * Logs a message with ERROR level.
     */
    void Error(std::string msg);
    
    /**
     * @brief Log a warning message
     * @param msg Warning message to log
     * 
     * Logs a message with WARNING level.
     */
    void Warning(std::string msg);
    
    /**
     * @brief Log an info message
     * @param msg Info message to log
     * 
     * Logs a message with INFO level.
     */
    void Info(std::string msg);
    
    /**
     * @brief Save logs to file
     * 
     * Writes all logged messages to a file.
     */
    void SaveToFile();
    
    /**
     * @brief Set log level
     * @param level New log level to set
     */
    void SetLogLevel(LogLevel level);
    
    /**
     * @brief Get current log level
     * @return Current log level
     */
    LogLevel GetLogLevel() const;

private:
    LogLevel logLevel;              ///< Current log level
    std::vector<std::string> logMessages; ///< Stored log messages
};

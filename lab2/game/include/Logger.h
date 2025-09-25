#pragma once
#include <string>
#include <vector>

class Logger {
public:
    enum LogLevel { DEBUG, INFO, WARNING, ERROR };
    
    Logger();
    void Log(std::string msg);
    void Error(std::string msg);
    void Warning(std::string msg);
    void Info(std::string msg);
    void SaveToFile();
    void SetLogLevel(LogLevel level);
    LogLevel GetLogLevel() const;
private:
    LogLevel logLevel;
    std::vector<std::string> logMessages;
};

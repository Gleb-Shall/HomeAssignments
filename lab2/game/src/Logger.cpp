#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

Logger::Logger() : logLevel(INFO) {}

void Logger::Log(std::string msg) {
    std::cout << "[LOG] " << msg << std::endl;
    logMessages.push_back("[LOG] " + msg);
}

void Logger::Error(std::string msg) {
    std::cout << "[ERROR] " << msg << std::endl;
    logMessages.push_back("[ERROR] " + msg);
}

void Logger::Warning(std::string msg) {
    std::cout << "[WARNING] " << msg << std::endl;
    logMessages.push_back("[WARNING] " + msg);
}

void Logger::Info(std::string msg) {
    std::cout << "[INFO] " << msg << std::endl;
    logMessages.push_back("[INFO] " + msg);
}

void Logger::SaveToFile() {
    std::ofstream file("game_log.txt");
    if (file.is_open()) {
        for (const auto& msg : logMessages) {
            file << msg << std::endl;
        }
        file.close();
        std::cout << "Лог сохранен в файл game_log.txt" << std::endl;
    } else {
        std::cout << "Ошибка: не удалось сохранить лог в файл" << std::endl;
    }
}

void Logger::SetLogLevel(LogLevel level) {
    logLevel = level;
}

Logger::LogLevel Logger::GetLogLevel() const {
    return logLevel;
}

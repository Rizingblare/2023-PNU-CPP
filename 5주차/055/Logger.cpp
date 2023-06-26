#include <iostream>

#include "Logger.h"

int Logger::logLevel = 1;

void Logger::setLogLevel(int level){
    logLevel = level;
}

void Logger::debug(const std::string& msg, const std::string& tag){
    if (logLevel <= 0)
        std::cout << "[DEBUG][" << tag << "] " << msg << std::endl;
}

void Logger::info(const std::string& msg, const std::string& tag){
    if (logLevel <= 1)
        std::cout << "[INFO][" << tag << "] " << msg << std::endl;
}

void Logger::warning(const std::string& msg, const std::string& tag){
    if (logLevel <= 2)
        std::cout << "[WARNING][" << tag << "] " << msg << std::endl;
}

void Logger::error(const std::string& msg, const std::string& tag){
    if (logLevel <= 3)
        std::cout << "[ERROR][" << tag << "] " << msg << std::endl;
}


#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <iostream>

enum LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};


class Logger {
public:
    static void setLogLevel(int level);
    static void debug(const std::string& msg, const std::string& tag);
    static void info(const std::string& msg, const std::string& tag);
    static void warning(const std::string& msg, const std::string& tag);
    static void error(const std::string& msg, const std::string& tag);

private:
    static int logLevel;
};

#endif
#ifndef STRINGSPLITTER_H_INCLUDED
#define STRINGSPLITTER_H_INCLUDED

#include <iostream>
#include <vector>

class StringSplitter {
    std::string msg;

public:
    StringSplitter(const std::string& str) : msg(str) {}

    StringSplitter& trim();
    StringSplitter& removeNonAlnum();
    std::vector<std::string> split(const char& sep);
};
#endif
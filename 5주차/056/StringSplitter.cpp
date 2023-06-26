#include <iostream>
#include <vector>
#include <regex>

#include "StringSplitter.h"


StringSplitter& StringSplitter::trim() {
    //this->msg = std::regex_replace(this->msg, std::regex("/^\\s+|\\s+$/g"),"");
    this->msg = std::regex_replace(this->msg, std::regex("^\\s+|\\s+$"),"");

    return *this;
}

StringSplitter& StringSplitter::removeNonAlnum() {
    //this->msg = std::regex_replace(this->msg, std::regex("/[^a-zA-Z0-9\\s]+/g"),"");
    this->msg = std::regex_replace(this->msg, std::regex("[^a-zA-Z0-9\\s]+"),"");

    return *this;
}

std::vector<std::string> StringSplitter::split(const char& sep) {
    std::vector<std::string> substr;

    std::stringstream ss(this->msg);
    std::string item;
    while (std::getline(ss, item, sep)) {
        substr.push_back(item);
    }

    return substr;
}

//std::vector<std::string> StringSplitter::split(const char& sep) {
//    std::vector<std::string> substr;
//
//    size_t start = 0, end = 0;
//    while ((end = this->msg.find(sep, start)) != std::string::npos) {
//        substr.push_back(this->msg.substr(start, end - start));
//        start = end + 1;
//    }
//    substr.push_back(this->msg.substr(start));
//
//    return substr;
//
//}
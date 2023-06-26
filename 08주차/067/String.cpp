#include <iostream>
#include <algorithm>

#include "String.h"

using namespace std;

void String::swap(String& str){

}

String::String() {
    len = 0;
    s = new char[1];
    s[0] = '\0';
}

String::String(const char* str) {
    const char* p = str;
    while (*p) { ++p; }
    len = p - str;

    if(str) {
        s = new char[len + 1];
        copy(str, str + len + 1, this->s);
    } else {
        s = new char[1];
        s[0] = '\0';
    }
}

String::String(const String& str) {
    len = str.len;
    s = new char[len + 1];
    copy(str.s, str.s + len + 1, this->s);
}

String& String::operator=(const String& str) {
    if (this != &str) {
        delete[] s;
        len = str.len;
        s = new char[len + 1];
        copy(str.s, str.s + len + 1, s);
    }
    return *this;
}

String::~String() {
    delete[] s;
    cout << "Destructor" << endl;
}

const char* String::data() const {
    return s;
}

char& String::at(size_t i) {
    return this->s[i];
}

size_t String::size() const {
    char* p = s;

    while (*p) { ++p; }

    return p - s;
}

void String::print(const char* str) const {
    cout << str << ": " << this->s << ", size: " << this->len << endl;
}
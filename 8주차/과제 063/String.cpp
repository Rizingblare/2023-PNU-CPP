#include <iostream>
#include <algorithm>

#include "String.h"

using namespace std;

int String::count_ = 0;

String::String() {
    len_ = 0;
    data_ = new char[1];
    data_[0] = '\0';

    cout << "Default Constructor" << endl;
    count_++;
    cout << "# of String object: " << count_ << endl;
}

String::String(const char* str) {
    const char* p = str;
    while (*p) { ++p; }
    len_ = p - str;

    if(str) {
        data_ = new char[len_ + 1];
        copy(str, str + len_ + 1, data_);
    } else {
        data_ = new char[1];
        data_[0] = '\0';
    }

    cout << "Constructor" << endl;
    count_++;
    cout << "# of String object: " << count_ << endl;
}

String::String(const String& str) noexcept {
    len_ = str.len_;
    data_ = new char[len_ + 1];
    copy(str.data_, str.data_ + len_ + 1, data_);
    cout << "Copy Constructor" << endl;
    count_++;
    cout << "# of String object: " << count_ << endl;
}

String::~String() {
    delete[] data_;
    cout << "Destructor" << endl;
    count_--;
    cout << "# of String object: " << count_ << endl;
}

const char* String::data() const {
    return data_;
}

bool String::empty() const {
    return data_[0] == '\0';
}

size_t String::size() const {
    char* p = data_;

    while (*p) { ++p; }

    return p - data_;
}

String& String::append(const String& str) {
    char* new_data = new char[len_ + str.len_ + 1];

    copy(data_, data_ + len_, new_data);
    copy(str.data_, str.data_ + str.len_ + 1, new_data + len_);

    len_ += str.len_;
    data_ = new_data;

    return (*this);
}

//
//String& String::append(const char* str) {
//    return *this;
//}
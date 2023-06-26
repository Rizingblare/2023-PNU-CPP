//
// Created by Rizingblare on 2023-04-24.
//

#ifndef INC_230308_FACULTY_H
#define INC_230308_FACULTY_H

#include <string>
class Faculty {
public:
    Faculty();
    Faculty(std::string name, int num) : name(name), num(num) {}

    const Faculty* get() const { return this; }
    std::string getName() { return this->name; }
    int getNum() { return this->num; }

private:
    std::string name;
    int num;
};

#endif //INC_230308_FACULTY_H

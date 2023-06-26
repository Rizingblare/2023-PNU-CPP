//
// Created by Rizingblare on 2023-04-24.
//

#ifndef INC_230308_DEPARTMENT_H
#define INC_230308_DEPARTMENT_H

#include <string>
#include "Faculty.h"

class Department {
public:
    Department(std::string name) : name(name), faculty(nullptr) {}
    Department(std::string name, Faculty* faculty) : name(name), faculty(nullptr) {}

    Faculty* getFaculty() { return this->faculty; }
    void setFaculty(Faculty* faculty) { this->faculty = faculty; }
    std::string getName() { return this->name; }

private:
    std::string name;
    Faculty* faculty;
};

#endif //INC_230308_DEPARTMENT_H

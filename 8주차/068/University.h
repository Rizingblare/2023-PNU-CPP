//
// Created by Rizingblare on 2023-04-24.
//

#ifndef INC_230308_UNIVERSITY_H
#define INC_230308_UNIVERSITY_H

#include <iostream>
#include <string>
#include "Department.h"

using namespace std;

class University {
public:
    University(std::string name, int num) : name(name), numDepartments(num) {}

    void setDepartments(Department* depts) { this->departments = depts; }

    void printInfo() {
        cout << "University Name: " << this->name << endl;
        cout << "Number of Departments: " << this->numDepartments << endl << endl;

        for (int i = 0; i < this->numDepartments; i++) {
            cout << "Department Name: " << this->departments[i].getName() << endl;
            if (this->departments[i].getFaculty()){
                cout << "Faculty Name: " << this->departments[i].getFaculty()->getName() << endl;
                cout << "Number of Faculty Members: " << this->departments[i].getFaculty()->getNum() << endl << endl;
            }
            else {
                cout << "Faculty Name: N/A" << endl;
                cout << "Number of Faculty Members: N/A" << endl << endl;
            }

        }
    }
private:
    std::string name;
    int numDepartments;
    Department* departments;
};

#endif //INC_230308_UNIVERSITY_H

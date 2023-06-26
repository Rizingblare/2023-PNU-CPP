//
// Created by Rizingblare on 2023-05-24.
//

#ifndef INC_230308_EMPLOYEE_H
#define INC_230308_EMPLOYEE_H

#include <iostream>
using namespace std;

// Employee.h
class Employee {
public:
    Employee(string name, int salary) : name_(name), salary_(salary) {}
    virtual void print_report() const {
        cout << "Name: " << name_ << endl;
        cout << "Salary: " << salary_ << endl;
        cout << "Years of service: " << years_of_service_ << endl;
        cout << "Performance score: " << performance_score_ << endl;
    }
    string get_name() const {
        return name_;
    }
protected:
    string name_;
    int salary_;
    int years_of_service_ = 0;
    int performance_score_ = 0;
};

class Manager : public Employee {
    string department_;
public:
    Manager(const string& name, int salary, const string& department)
    : Employee(name, salary), department_(department) {}

    void set_goals() {
        cout << "Set goals for " << department_ << endl;
    }

    virtual void print_report() const {
        Employee::print_report();
        cout << "Department: " << department_ << endl;
    }
};

class Programmer : public Employee {
    string language_;
public:
    Programmer(const string& name, int salary, const string& language)
    : Employee(name, salary), language_(language) {
        Employee::performance_score_ = 10;
    }

    void write_code() {
        cout << "Writing code in " << language_ << endl;
    }

    virtual void print_report() const {
        Employee::print_report();
        cout << "Language: " << language_ << endl;
    }
};

class Salesperson : public Employee {
    int sales_;
public:
    Salesperson(const string& name, int salary, int sells)
            : Employee(name, salary), sales_(sells) {
        Employee::performance_score_ = 20;
    }

    void sell() {
        cout << "Selling products, generated " << sales_ << " in revenue" <<  endl;
    }

    virtual void print_report() const {
        Employee::print_report();
        cout << "Sales: " << sales_ << endl;
    }
};

#endif //INC_230308_EMPLOYEE_H

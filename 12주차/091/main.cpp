#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;

public:
    Person(const string& _name) : name(_name) {
        cout << "Person is constructed!" << endl;
    }

    ~Person() { cout << "Person is destructed!" << endl; }

    void print() {
        cout << "Person Name: " << name << endl;
    }
};

class Student : public Person {
    string schoolName;

public:
    Student(string _name, string _schoolName) : Person(_name), schoolName(_schoolName) {
        cout << "Student is constructed!" << endl;
    }

    ~Student() { cout << "Student is destructed!" << endl; }

    void print() {
        Person::print();
        cout << "School Name: " << schoolName << endl;
    }
};


int main() {
    Person p1{"Park"};
    p1.print();

    Student s1 {"Kim", "PNU"};
    s1.print();

    return 0;
}
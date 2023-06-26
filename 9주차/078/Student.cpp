#include "Student.h"

bool Student::operator< (const Student& other) const {
    return name < other.name;
}

std::ostream& operator << (std::ostream& os, const Student& s) {
    os << "Id: " << s.id << " Name: " << s.name << " Grade: " << s.grade;
    return os;
}

bool compareByGrade(const Student& a, const Student &b) {
    return a.getGrade() > b.getGrade();
}
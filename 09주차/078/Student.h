#include <ostream>

class Student {
public:
    Student() {}
    Student(int _id, const std::string& _name, int _grade) : id(_id), name(_name), grade(_grade) {}
    int getGrade() const { return this->grade; }

    bool operator< (const Student& other) const;
    friend std::ostream& operator << (std::ostream& os, const Student& c);
private:
    int id;
    std::string name;
    int grade;

};

std::ostream& operator << (std::ostream& os, const Student& c);
bool compareByGrade(const Student& a, const Student& b);
#include <iostream>

using namespace std;

class Person {
public:
    static int id;

    Person(std::string name, size_t age) : name{name}, age{age} {
        ID = id++;
    }

    friend std::ostream& operator << (std::ostream& out, const Person& p) {
        cout << p.ID << " " << p.name << " " << p.age;
        return out;
    }

    bool operator < (const Person& rhs) const {
        return this->ID < rhs.ID;
    }

    class ComparatorByAge {
    public:
        bool operator()(const Person& lhs, const Person& rhs) const{
            return lhs.age < rhs.age;
        }
    };

    class ComparatorByName {
    public:
        bool operator()(const Person& lhs, const Person& rhs) const {
            return lhs.name < rhs.name;
        }
    };

private:
    long long ID;
    std::string name;
    size_t age;
};

int Person::id = 1;
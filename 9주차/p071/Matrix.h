#include <iostream>

using namespace std;

class matrix {
public:
    matrix(std::initializer_list<std::initializer_list<int>> values);
    matrix(const matrix&);

    ~matrix();

    matrix& operator+(const matrix&);
    matrix& operator=(const matrix&);


    matrix& inverse();
    friend ostream& operator<<(ostream&, const matrix&);
    // 생성자, 복사생성자
    // 연산자 오버로딩
    // 멤버 함수들
private:
    int* data = nullptr;
    size_t row = 0;
    size_t col = 0;
};

ostream& operator<<(ostream&, const matrix&);
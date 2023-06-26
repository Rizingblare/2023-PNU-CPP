#include <cmath>
#include <iostream>
#include <array>
#include <algorithm>

template <typename T, size_t N>
auto myFind(std::array<T, N>& arr, T target) {
    return std::find(arr.begin(),arr.end(), target);
}

class Complex {

    float r, i ;

public:
    Complex(float _r = 0.F, float _i = 0.F) : r(_r), i(_i) {}
    bool operator < (const Complex& c) const {
        return size() < c.size() ;
    }

    float size() const { return sqrt(r*r + i*i) ; }

    bool operator == (const Complex& c) const {
        return ( r == c.r && i == c.i ) ;
    }

    friend std::ostream& operator<< (std::ostream& os, const Complex& other);
};


std::ostream& operator<< (std::ostream& os, const Complex& rhs) {
    std::cout <<  rhs.r << " + " << rhs.i << "i";
    return os;
}
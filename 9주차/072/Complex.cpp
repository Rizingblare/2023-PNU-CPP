#include "Complex.h"

std::ostream& operator << (std::ostream& os, const Complex& c) {
    os << c.r << "+" << c.i << "i";
    return os;
}

Complex Complex::operator + (const Complex rhs){
    return Complex(r + rhs.r, i + rhs.i);
}

Complex Complex::operator - (const Complex rhs){
    return Complex(r - rhs.r, i - rhs.i);
}
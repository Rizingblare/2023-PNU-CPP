#include <iostream>
#include <iomanip>

#include "Temperature.h"

using namespace std;

Temperature::Temperature(double temp, SCALE scale): temperature(temp), scale(scale){}

Temperature Temperature::add(Temperature other) {
    bool isSameScale = ( this->scale == other.scale );

    float result;

    if (this->scale == CELSIUS){
        if (isSameScale == 0)
            other.convertToCelsius();
    }

    else if (this->scale == FAHRENHEIT) {
        if (isSameScale == 0)
            other.convertToFahrenheit();
    }

    result = this->temperature + other.temperature;

    return Temperature {result, this->scale};
}

std::string Temperature::print() const {
    std::stringstream ss;
    ss << std::fixed;
    ss << std::setprecision(1);
    if (this->scale == FAHRENHEIT) {
        ss << this->temperature << " F\n";
    } else {
        ss << this->temperature << " C\n";
    }
    return ss.str();
}

void Temperature::convertToCelsius() {
    this->temperature = ((this->temperature) - 32) / 9 * 5;
    this->scale = CELSIUS;
}

void Temperature::convertToFahrenheit() {
    this->temperature = (this->temperature) * 1.8 + 32;
    this->scale = FAHRENHEIT;
}
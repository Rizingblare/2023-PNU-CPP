//
// Created by Rizingblare on 2023-04-24.
//

#ifndef INC_230308_VEHICLE_H
#define INC_230308_VEHICLE_H

#include <string>
class Vehicle {
public:
    Vehicle();
    Vehicle(std::string, int, float);
    Vehicle(std::string, int, bool, float);

    void autoPilot(bool onOff);
    void runFDS() const;
    void displayEfficiency() const;
private:
    std::string name;
    int range;
    bool hasFDS;
    float batteryCapacity;
};

#endif //INC_230308_VEHICLE_H

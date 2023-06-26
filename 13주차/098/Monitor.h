//
// Created by Rizingblare on 2023-05-24.
//

#ifndef INC_230308_MONITOR_H
#define INC_230308_MONITOR_H

#include <iostream>
#include "OutputDevice.h"

class Monitor : public OutputDevice {
public:
    Monitor() { std::cout << "Monitor constructor" << std::endl; }
    ~Monitor() { std::cout << "Monitor destructor" << std::endl; }
};

#endif //INC_230308_MONITOR_H

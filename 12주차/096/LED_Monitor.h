//
// Created by Rizingblare on 2023-05-24.
//

#ifndef INC_230308_LED_MONITOR_H
#define INC_230308_LED_MONITOR_H

#include <iostream>
#include "Monitor.h"

class LED_Monitor : public Monitor {
public:
    LED_Monitor() { std::cout << "LED_Monitor constructor" << std::endl; }
    ~LED_Monitor() { std::cout << "LED_Monitor destructor" << std::endl; }
};

#endif //INC_230308_LED_MONITOR_H

//
// Created by Rizingblare on 2023-05-24.
//

#ifndef INC_230308_LCD_MONITOR_H
#define INC_230308_LCD_MONITOR_H

#include <iostream>
#include "Monitor.h"

class LCD_Monitor : public Monitor {
public:
    LCD_Monitor() { std::cout << "LCD_Monitor constructor" << std::endl; }
    ~LCD_Monitor() { std::cout << "LCD_Monitor destructor" << std::endl; }
};

#endif //INC_230308_LCD_MONITOR_H

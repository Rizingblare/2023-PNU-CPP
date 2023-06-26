//
// Created by Rizingblare on 2023-05-24.
//

#ifndef INC_230308_PRINTER_H
#define INC_230308_PRINTER_H

#include <iostream>
#include "OutputDevice.h"

class Printer : public OutputDevice {
public:
    Printer() { std::cout << "Printer constructor" << std::endl; }
    ~Printer() { std::cout << "Printer destructor" << std::endl; }
};


#endif //INC_230308_PRINTER_H

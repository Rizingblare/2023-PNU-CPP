//
// Created by Rizingblare on 2023-05-24.
//

#ifndef INC_230308_OUTPUTDEVICE_H
#define INC_230308_OUTPUTDEVICE_H

#include <iostream>

class OutputDevice {
public:
    OutputDevice() { std::cout << "OutputDevice constructor" << std::endl; }
    virtual ~OutputDevice() { std::cout << "OutputDevice destructor" << std::endl; }
};

#endif //INC_230308_OUTPUTDEVICE_H

#include <iostream>

#include "Cell.h"

Cell::Cell() {}
Cell::Cell(std::string val) : type(STRING), stringVal(val) {}
Cell::Cell(int val) : type(INT), intVal(val) {}
Cell::Cell(double val) : type(DOUBLE), doubleVal(val) {}

CELL_TYPE Cell::getType() const { return this->type; }
std::string Cell::getStringVal() const { return this->stringVal; }
int Cell::getIntVal() const { return this->intVal; }
double Cell::getDoubleVal() const { return this->doubleVal; }
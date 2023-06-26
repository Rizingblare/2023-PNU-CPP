#include <iostream>
#include <vector>

#include "Excel.h"
#include "Cell.h"

Excel::Excel(std::vector<std::vector<Cell>> data) : data(data) {}

double Excel::average(int fromRow, int fromCol, int toRow, int toCol) const {
    double sum = 0;
    double cnt = 0;

    for (int i = fromRow; i <= toRow; i++){
        for (int j = fromCol; j <= toCol; j++){
            if (this->data[i][j].getType() == INT)
                sum += this->data[i][j].getIntVal();
            else if (this->data[i][j].getType() == DOUBLE)
                sum += this->data[i][j].getDoubleVal();
            else continue;
            cnt += 1;
        }
    }

    return sum / cnt;
}
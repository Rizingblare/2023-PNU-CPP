#include "Matrix.h"

#include <iostream>

using namespace std;

matrix::matrix(std::initializer_list<std::initializer_list<int>> values) {
    row = values.size();
    col = values.begin()->size();
    data = new int[row * col];
    int i = 0;

    for (auto row : values) {
        int j = 0;
        for (auto elem : row) {
            data[i * col + j] = elem;
            j++;
        }
        i++;
    }
}

matrix::matrix(const matrix& other){
    row = other.row;
    col = other.col;
    data = new int[row * col];
    copy(other.data, other.data + row* col, data);
};

matrix::~matrix() {
    delete[] data;
}

matrix& matrix::operator=(const matrix& other){
    if (this != &other) {
        delete[] data;
        row = other.row;
        col = other.col;
        data = new int[row * col];
        copy(other.data, other.data + row* col, data);
    }
    return *this;
}

matrix& matrix::operator+(const matrix& other){
    for (int i = 0; i < row * col; i++)
            data[i] += other.data[i];

    return (*this);
}

matrix& matrix::inverse(){
    if (row * col == 0) return (*this);

    int det = this->data[0]*this->data[3]-this->data[1]*this->data[2];
    matrix* invMatrix = new matrix {
                            {
                                    this->data[3] / det,
                                    -this->data[1] / det
                            },

                            {
                                    -this->data[2] / det,
                                    this->data[0] / det
                            },
                        };

    return *invMatrix;
}

ostream& operator<<(ostream& os, const matrix& object) {
    if (object.row == 1 && object.col == 0)
        cout << "||" << endl;

    else {
        for (int i = 0; i < object.row * object.col; i++) {
            if (i % object.col == 0) cout << "| ";
            cout << object.data[i] << " ";
            if (i % object.col == object.col - 1) cout << "|" << endl;
        }
    }

    return os;
}

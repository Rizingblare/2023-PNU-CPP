#include "Array.h"

#include <iostream>
#include <memory>

using namespace std;

Array::Array(std::initializer_list<int> args, size_t size)
: data(new int[size]), _size(size)
{
    copy(args.begin(), args.end(), data.get());

//    int cnt = 0;
//    for (auto itr = args.begin(); itr != args.end(); ++itr) {
//        data[cnt] = *itr;
//        cnt++;
//    }

}

int& Array::operator [] (int index) {

    return data[index];
}

size_t Array::size() const {
    return _size;
}

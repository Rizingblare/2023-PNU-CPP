#include <cstddef>
#include <complex>
#include <vector>
#include <algorithm>
#include <iostream>

template<typename T, size_t N>
class MyList {
public:
    MyList(): _data(new T[N]) {}
    MyList(const MyList& rhs) noexcept {
        _data = new T[N];
        pos = rhs.pos;
        std::copy(rhs._data, rhs._data + rhs.pos, _data);
    }
    MyList& operator=(const MyList& rhs) {
        if (this != &rhs) {
            delete[] _data;
            _data = new T[N];
            pos = rhs.pos;
            std::copy(rhs._data, rhs._data + rhs.pos, _data);
        }
        return *this;
    }
    ~MyList() noexcept { delete[] _data; }

    void add(T& data) {
        _data[pos] = data;
        pos++;
    }

    void remove(T& data) {
        bool isExist = false;
        int idx = 0;
        for (T* iter = _data; iter < _data + N; iter++) {
            if (*iter == data) {
                isExist = true;
                break;
            }
            else idx++;
        }

        if (isExist) {
            T* temp = new T[N];
            std::copy(_data, _data + idx, temp);
            std::copy(_data + idx + 1, _data + N, temp + idx);

            delete[] _data;
            _data = temp;
            pos--;
        }

    }

    const T* begin() const {return _data;}
    const T* end() const {return _data + N;}

    T* begin() {return _data;}
    T* end() {return _data + N;}

    bool operator==(const T& other) const { return _data == other; }

private:
    T* _data= nullptr;
    int pos = 0;
};
//
// Created by Suman on 13-05-2024.
//

#include <stdexcept>


class Array {
    int* values;
    size_t size;

public:
    explicit Array(size_t size) {
        values = new int[size];
        this->size = size;
    }


    // signature : arr[index]:int => this will return int value so we kept int.
    int& operator[](size_t index) {
        if (index >= size) throw std::invalid_argument("index");

        return values[index];

    }



};

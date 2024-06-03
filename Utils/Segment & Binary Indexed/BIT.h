#pragma  once

#include <iostream>
#include<vector>
#include<stdexcept>

class BIT {

    int _capacity;
    int *_container = nullptr;
    int *_base = nullptr;

public:

    explicit BIT(std::vector<int> &vec) {
        _capacity = vec.size();
        _base = vec.data();
        _container = new int[_capacity + 1]{0}; // 0 index in unused in trie.

        // construct trie
        for(int i=0;i<_capacity;i++){
            constructTree(i,_base[i]);
        }
    }

    int getRangeSum(int end, int start = -1) {
        if (end < 0 || end >= _capacity) throw std::out_of_range("Invalid Index : " + std::to_string(end));
        if (start > end) throw std::out_of_range("Start Index can not be greater then end index");

        int result = 0;

        result = getSum(end);

        if (start != -1) result -= getSum(start);

        return result;


    }

    void constructTree(int index,int val){
        index=index+1; // BIT starts from 1

        if (index < 0 || index > _capacity) throw std::out_of_range("Invalid Index : " + std::to_string(index));
        while (index <= _capacity) {
            _container[index] += val;
            index = index + (index & -index);
        }
    }

    void updateIndex(int index, int newValue) {

        if (index < 0 || index >= _capacity) throw std::out_of_range("Invalid Index : " + std::to_string(index));

        int diff = newValue - _base[index];

        // update the base array
        _base[index] = newValue;

        index=index+1; // BIT starts from 1
        // update the udated value in all index in which it's part of
        while (index <= _capacity) {
            _container[index] += diff;
            index = index + (index & -index);
        }


    }

    void showBIT(){
        for(int i=0;i<=_capacity;i++){
            std::cout << "Index: " <<i << " Value: " << _container[i] << std::endl;
        }
    }


    ~BIT() {
        delete[] _container;
        _container = nullptr;

    }

private:
    int getSum(int index) {
        index++; // since BIT starts from 1 and we are giving index based on array

        int result = 0;

        while (index != 0) {
            result += _container[index];
            index = index - (index & -index);
        }

        return result;
    }


};
#pragma once

#include<vector>
#include<iostream>


class SegmentTree {
    std::vector<int> *_container= nullptr;
    int* _base = nullptr;
    int _capacity = 0;

public:
    explicit SegmentTree( std::vector<int> &vec) {
        _capacity = vec.size() * 4;

        _base = vec.data();

        _container = new std::vector<int>(_capacity, 0);

        // construct the Segment Tree
        construct(0, vec.size() - 1, 0);
    }

    ~SegmentTree(){
        delete _container;
        _container = nullptr;
    }


    int getQuerySum(int start, int end) {
        return query(start, end, 0, (_capacity / 4) - 1, 0);
    }

    void showTree() {
        for (int i = 0; i < _capacity; i++) {
            std::cout << "i :" << i << "\tval:" << _container->at(i) << std::endl;
        }
    }

    void update(int index, int updatedValue) {
        // Calculate the diff
        int diff = updatedValue - _base[index];
        _base[index] = updatedValue;

        // update all the indices which uses that index as there part.
        updateTree(index,0,(_capacity/4)-1,0,diff);
    }

private:
    int construct(int start, int end, int index) {
        if (start == end) {
            _container->at(index) = _base[start];
            return _base[start];
        }

        int mid = start + (end - start) / 2;

        int leftSum = construct(start, mid, 2 * index + 1);
        int rightSum = construct(mid + 1, end, 2 * index + 2);

        _container->at(index) = leftSum + rightSum;

        return _container->at(index);
    }

    int query(int qs, int qe, int ss, int se, int index) {
        // if complete out of range , then return 0
        if (qs > se || ss > qe) return 0;

        // if complete inside the range
        if (qs <= ss && qe >= se) return _container->at(index);

        // else , try to reach to the correct position position
        int mid = ss + (se - ss) / 2;
        int leftResult = query(qs, qe, ss, mid, 2 * index + 1);
        int rightResult = query(qs, qe, mid + 1, se, 2 * index + 2);
        return leftResult + rightResult;
    }

    void updateTree(const int &index, int ss, int se,int si, const int &diff) {
        // if out of range then return
        if (index < ss || index > se) return;

        
        _container->at(si) = _container->at(si) + diff;


        // if it's not the end node
        if(se>ss) {

        // otherwise go to left and right subtree for updation
        int mid = ss + (se - ss) / 2;
        updateTree(index, ss, mid, 2 * si + 1,diff);
        updateTree(index, mid + 1, se, 2 * si + 2,diff);

        }

    }
};

#pragma once
#include<iostream>
#include "LinkedList/Doubly.h"
using namespace std;

struct vector3 {
    int x,y,z;

    friend std::ostream& operator<<(std::ostream& os,const vector3& node) {
        os << "vector3("<<node.x<<node.y<<node.z<< ")";
        return os;
    }
};

class TestSuit {

public :
    static void test() {

    Doubly doubly(10);
    std::cout<<"->> Uitlis test" <<std::endl;

    for(auto& element: doubly) cout<<"node("<<element<<")"<<endl;
}


};

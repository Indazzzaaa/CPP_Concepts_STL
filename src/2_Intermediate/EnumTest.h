
#ifndef ENUMTEST_H
#define ENUMTEST_H

#include<iostream>
using namespace  std;

enum Color {
    RED,BLUE,GREEN

};

enum Color2 {
    // RED, shows error
    ORANGLE,
    PURPLE
};

// class enum allows us to create with same field
enum class Color3 {
    RED, PURPLE
};

enum class Color4 {
    RED,PURPLE
};

inline void enum_test_one() {

    // Both gives same value 0 , which not good for us , RED!= ORANGLE
    cout<<Color::RED<<endl;
    cout<<Color2::ORANGLE<<endl;

    // enum with class
    // cout<< Color3::RED <<endl; // this will give us error .
    cout<< static_cast<int>(Color3::RED) <<endl; // we have to explicit cast it.
}

#endif //ENUMTEST_H

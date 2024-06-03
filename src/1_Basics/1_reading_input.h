#ifndef INC_1_READING_INPUT_H
#define INC_1_READING_INPUT_H

#include<iostream>
using namespace std;


inline void read_data() {
    cout << "Enter a value:";
    int value;
    cin >> value;
    cout << "->>You have entered value: " << value << endl;
}

inline void read_multiple_value() {
    cout << "Enter values for x and y:";
    double x, y;
    cin >> x >> y; // cin chooses next value based on space or enter(\n)
    cout << "->>Sum of x and y is : " << x + y << endl;
}


inline void compound_interest(double principal, const float annual_interest, unsigned short years) {
    // check for base case
    if (years == 0) {
        cout << "->> Your amount will be : " << principal << endl;
    }

    // new principle
    principal = principal*(1 + (annual_interest / 100));
    years--;

    compound_interest(principal,annual_interest,years);
}

inline void  test_input_system() {
    cout<<"->>[Basics]"<<endl;
    compound_interest(1000,10,10);
}




#endif //INC_1_READING_INPUT_H

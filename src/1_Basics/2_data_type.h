//
// Created by Suman on 07-05-2024.
//

#ifndef INC_2_DATA_TYPE_H
#define INC_2_DATA_TYPE_H

#include<iomanip> // for manipulating our streams
#include<limits>
using namespace std;

inline void data_type_test() {
    double price = 99.99;
    auto another_price = 99.99;

    // with floats values alway suffix them with f.
    // otherwise comipler will first create double then assign them to float which leads to loss in data.
    float interestRate = 3.76f;
    long fileSize = 90000L; // otherwise compiler will create int and assing to long.
    char letter = 'a';
    bool is_valid = false;
    auto is_another_valid = false;

    // way to  initialize variables.
    int n1 = 1.2;
    // int n2{1.2}; //with brace initializer if we initialize wrong type it will throw error.
    int n3(1.2);
    cout << n3 << endl;
}

inline void diff_num_system() {
    int n1 = 10; // decimal
    int n2 = 0111; // octal
    int n3 = 0xff; // hexadecimal
    int n4 = 0b11; // binary

    int n11 = 1'000'000; // formatting big number

    unsigned int n5{1};
    //unsigned int n6{-11}; // here we get error , but conventional way won't have thrown any error in that case.

    cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
}

inline void formatting_data() {
    // setw : put space for character comes after.
    // left : for left align.(it's sticky) default is right align
    cout << "->>" << setw(10) << "Spring" << "Nice" << endl;

    // format float numbers
    // box fixed and setprecision are sticky , so it's effect will apply to all next.
    cout << fixed << 12.34567 << endl;
    cout << setprecision(1) << 12.34567 << endl;

    // let's format some data to see.
    cout << left;
    cout << setw(15) << "Courses" << setw(10) << "Student" << endl
            << setw(15) << "C++" << setw(10) << right << 100 << left << endl
            << setw(15) << "JavaScript" << setw(10) << right << 150 << left << endl;
}

inline void data_type_size() {
    cout << "->> Size of int: " << sizeof(int) << endl;
    cout << "Max : " << numeric_limits<int>::min() << endl
            << "Min: " << numeric_limits<int>::max() << endl;
}

inline void array_test() {
    int arr[5];
    cout << "First value: " << arr[0] << endl;
    cout<< "Size of arr: " << size(arr) <<endl;

    int* arr2 = new int[5];
    cout<<"First value: " << arr2[0]<<endl;
}


inline void test() {
    array_test();
}


#endif //INC_2_DATA_TYPE_H

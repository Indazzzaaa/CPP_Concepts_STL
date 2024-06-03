//
// Created by Suman on 11-05-2024.
//

#ifndef STREAMTEST_H
#define STREAMTEST_H

#include<iostream>
#include<limits>


using namespace  std;

class StreamTest {

public:
    static void get_input() {
        int first;

        while (true) {
            cout<<"First: " ;
            cin >> first;

            // checking whether values entered was valid or not
            if(cin.fail()) {
                cout<<"Enter a valid number!" << endl;
                cin.clear(); // clear the state of cin , which was failed state earlier

                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }else {break;}
        }

        cout<<"You have entered value: " << first <<endl;

    }



};

#endif //STREAMTEST_H

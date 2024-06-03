
#ifndef STRINGTEST_H
#define STRINGTEST_H

#include <iostream>
#include<string_view>

using namespace  std;

inline void get_sub_str() {
    string str1 = "Sumant Patel";
    string_view sv1 = "Hello world";// string view from string literals.

    string_view sv2(str1);   // creates view over the str1 , without copying it.
    str1[0]='A'; // see the result.

    cout<< sv1.substr(0,3)<<endl;
    cout<< sv2<<endl;

    // compare the string.
    cout<< (str1==sv2)<<endl;
}



#endif //STRINGTEST_H

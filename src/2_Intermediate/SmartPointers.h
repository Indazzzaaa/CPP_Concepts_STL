#ifndef SMARTPOINTERS_H
#define SMARTPOINTERS_H

#include<iostream>
#include<memory>
using namespace  std;


inline void show_unique(unique_ptr<int>& x) {
    cout<<"->> value received is : " << *x<<endl;
}

inline  void unique_test() {
    unique_ptr<int> x(new int(10));
    show_unique(x); // can only pass using reference

    // to move owner ship use
    auto ptr2 = move(x);
    cout<<"->>After move data in ptr2: " << *ptr2<<endl;
    if(x==nullptr) cout<<"->> X don't have data anymore"<<endl;
    
}


inline void shared_ptr_test() {
    // Creating a shared pointer to an integer
    std::shared_ptr<int> ptr1(new int(42));

    // Creating two more shared pointers and sharing ownership
    std::shared_ptr<int> ptr2 = ptr1;
    std::shared_ptr<int> ptr3 = ptr1;

    // Modifying the value through one of the pointers
    *ptr2 = 100;

    // Accessing the value through all three pointers
    std::cout << "Value held by ptr1: " << *ptr1 << std::endl;
    std::cout << "Value held by ptr2: " << *ptr2 << std::endl;
    std::cout << "Value held by ptr3: " << *ptr3 << std::endl;
}



#endif //SMARTPOINTERS_H

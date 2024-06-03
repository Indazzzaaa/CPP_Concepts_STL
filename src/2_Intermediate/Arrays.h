
#ifndef ARRAYS_H
#define ARRAYS_H
#include<iomanip>

using namespace  std;


inline void traversing() {

    int numbers[] = {1,2,3};
    int* numbers2 = new int[]{1, 2, 3};
    cout<< "First vlaue is: " << numbers[1]<<endl;
    cout<<"First value is: " << *(numbers+1)<<endl;

    size_t size1 = sizeof(numbers)/sizeof(int);
    size_t size2 = size(numbers);

    // way to traverse array
    cout<<left<<setw(4);
    for(int i=0;i<size1;i++) cout<<numbers[i]<<setw(4);
    cout<<endl;

    // using for each (below is memory efficient way to traverse array
    for(const int& num : numbers) cout<< num<<setw(4);
    cout<<endl;


    // Destructuring test
    auto [x,y,z] = numbers;
    delete numbers2; //de-allocating the memory allocated



}





#endif //ARRAYS_H

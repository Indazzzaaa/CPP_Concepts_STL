#pragma once

class SmartPointer
{
    int* ptr;

public:
    explicit SmartPointer(int* ptr);
    ~SmartPointer();

    // Overloading the indirection operator to get the data stored in smart pointer
    /*
        SmartPointer ptr{new int};
        *ptr =101; // that's where indirection operator overload will work
     */
    int& operator*();

};


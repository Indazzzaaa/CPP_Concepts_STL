#include "Length.h"
#include<iostream>

Length::Length(int value): value(value){}

int Length::getValue() const
{
    return value;
}

void Length::setValue(int newVal)
{
    value = newVal;
}

Length Length::operator+(const Length& other) const
{
    // we are returning new length object.
    return Length(value+other.value);
}

Length Length::operator+(const int val) const
{
    return Length(value+val);
}

Length& Length::operator+=(const Length& other)
{
    value += other.value;
    return *this; // by deref the this we get the actual Length object. This is tricky part here.


}

Length& Length::operator=(const Length& other)
{
    std::cout << "Object Assigned" << std::endl;
    value = other.value;
    return *this;
}

Length& Length::operator++()
{
    value++;
    return *this;
}

Length Length::operator++(int)
{
    Length copy = *this; // copy constructor will be called.
    operator++();
    return copy;
}

bool Length::operator==(const Length& other) const
{
    return value == other.value;
}

bool Length::operator==(int other) const
{
    return value == other;
}

std::strong_ordering Length::operator<=>(const Length& other) const
{
    return  value <=> other.value;
}


bool Length::operator<(const Length& other) const
{
    return value<other.value;
}





bool Length::operator<=(const Length& other) const
{
    return !(value>other.value);
}

bool Length::operator>(const Length& other) const
{
    return value>other.value;
}

bool Length::operator>=(const Length& other) const
{
    return !(value<other.value);
}

Length::operator int() const
{
    return value;
}


// Because of being friend it can access the value property
std::ostream& operator<<(std::ostream& stream, const Length& length)
{
    stream << length.value;
    return stream;


}

std::istream& operator>>(std::istream& stream,  Length& length)
{
    int newValue;
    stream >> newValue;
    length.setValue(newValue);
    return stream;



}

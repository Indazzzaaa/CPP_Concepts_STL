#pragma once

#include<compare> // for using strong_ordering enum.
#include<ostream>
#include<istream>

/*
SpaceShip Operator : it does 3 things in one operator
 auto result= x<=>y // means x is less then , equal to , or greater then y;
 if(result == stong_ordering::less) {}
 else if (result == strong_ordering::greater){}
 else {}


 */

class Length
{
	int value;

public:
	explicit Length(int value);

	int getValue() const;
	void setValue(int newVal);

	// Overloading arithmetic operator , so we can add length1+length2
	Length operator+(const Length& other) const;
	Length operator+(const int val) const; // so we can do length+10;


	// overloading compound assignment operators.
	// This is little tricky to implement so see it's implementation.
	Length& operator+=(const Length& other); // in this current object is modified length+=length2 , that's why we don't mark as constant.

	// overloading assignment operator : this is called when we assign value later like length1=length2;
	/*
	The equal sign has different meaning at different context.
	eg.
		Length first{10};
		Length second =first; // this represent the copy operaton(Copy constructor calls)
		Length third(30);
		third = first; // this calls the overloaded assignment operator.

		// if we think to delete the copy constructor then we must also delte the assignment operator for that class and how to delete we know that, so compiler won't create the default as well.
		// The default assignment operator and copy constructor works almost all the time except we have manually allocated something on heap and wan't to tackle how we want's them to copy.

	*/
	Length& operator=(const Length& other);


	// Overloading Unary Operator , it can applied to postfix or prefix form.
	Length& operator++(); // prefix, here we modify the existing object
	Length operator++(int); // post fix, here we return the new object.



	// overloading == operator : if we overload == operator , compiler will automatically overload != for us , so we don't have to write it.
	bool operator==(const Length& other) const;
	bool operator==(int other) const; // so we can compare Length==10; don't use & because for primitives there is no performance gain by passing them by reference


	// with spaceship overload , we can ommit the all below relational operators.
	// so only need two operator , equality and Spaceship . And compiler will all other for us based on space ship and equality.
	std::strong_ordering operator<=>(const Length& other) const; // c++ 20

	// overloading the comparison operator
	bool operator<(const Length& other) const;




	// with space ship operator we can omit below three overloads.
	bool operator<=(const Length& other) const;
	bool operator>(const Length& other) const;
	bool operator>=(const Length& other) const;

	// with this way we made this function frient of this class so it can access it's private memembers , which is veryusefull, but stream extraction operator is not overloaded as friend just to show we can go with frient way or without friend way.
	friend std::ostream& operator<<(std::ostream& stream, const Length& length);



	/*
	  how we want to convert our class when assinged to primities or other data type for that we can take below way for type conversion.
	  Length l{10};
	  int age = l; // currently it won't work but after implementig below overload it will.

	  but if we use explicit before operator then we have to use below syntex to cast.
	  int age = static_cast<int>(length);
	*/
	operator int() const; // sytenx is , operator conversion_type() const(since we are not modifying the body of the class);

};

// overloading insertion operator, and it's overloaded out side the class.
// Because for all other operator we have assumed that on leftSide is current class but this is not true for this case.
// overloading this operator gives us power to define custom output view for our class.
std::ostream& operator<<(std::ostream& stream, const Length& length); // we have commented that because we declared this as friend of the class .

// overloading the stream extraction operator
std::istream& operator>>(std::istream& stream, const Length& length);



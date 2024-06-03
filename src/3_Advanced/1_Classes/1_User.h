#pragma once

#include<iostream>
using namespace std;

/*
[To know about]
Classes
Access Modifiers
Construtors
Destructors
*/


/*
1. Class is just blueprint.It does not allocates memory itself.
2. Encapsulation: Combining the data and functions that operate on the data into one unit.
3. Use of explict keyword.
*/

// By default class variables are private while in structs it's public.
// By default compiler generates default constructor for each class , untill we define our own so then it won't create default one then.
// explicit Keyword : We use this before the name of constructor so compiler does not do conversion.

// constant objects : when we create object with const keyword like we do for any primitive , compiler makes all it's memembers constant.
// and effect of this is data won't be modifiable, any method created without const body won't be callable.
// Best practice if , we are not changing value in function mark const before them.

class Rectangle {
	int width{};
	int height{};
	string color;
	static int objectCount;


public:

	Rectangle() = default;
	Rectangle(int width, int height);

	// if some funciton parameter requires Rectangle we could have passed just integer there instead of Rectangle object , but now compiler won't allow to do that.
	explicit Rectangle(int width);

	// example of calling other constructor
	Rectangle(int width, int height, const string& color);


	/*Copy constructor
	 For data created on heap have to manually write the copy constructor to do deep copy.
	 and other cases compiler default works fine.
	 It is called, when used leftValue=rightValue, and passing to function.
	 Conclusion : Untill unless needed deep copy , go with default compiler generates for us.
	 if want's to delete copy constructor : Rectangle(const Rectangle& source) = delete;  // we are saying compiler that we don't want copy constructor.
	 in this case all operations were we assing = , or pass to function won't work.
	*/
	Rectangle(const Rectangle& source);

	/*Destructors
		They are automatically called when our objects are being destroyed.
		Only need if we are allocating memory on the heap.
		We can't overload destructors, because it's have same signature always.
	*/
	~Rectangle();

	void draw();
	int getArea() const;
	// Getter (accessor)
	int getWidth() const;
	int getHeight() const;
	// Setter (mutator)
	void setWidth(int width);
	void setHeight(int height);

	// we can use only static members inside the static function.
	static int getObjectCount();






};


/* Pointer to object
auto* rectangle = new Rectangle(10,20);
rectangle->draw();
delete rectangle; // to save from memory leak
rectangle = nullptr; // to save from being dangling.

[In modern-cpp ]
we should not use new and delete , instead we should use smart pointers.
So use unique and shared pointers.They will take care of de-allocating and allocating or memory.

auto rectangle = make_unique<Rectangle>(10,20);
rectangle->draw(); // no need to worry about de-allocating and fixing dangling issue.

*/


/*
Array of objects

[way-1]
Rectangle rectangle[] = { Rectangle(),Rectangle(10,20),Rectangle(10,20,"blue")};

[way-2]
Rectangle rectangle[] = { {},{10,20},{10,20,"blue"}};

// efficiently looping over array of objects.
for(Rectangle& rect: rectangles) rect.draw();
// if we don't use & , then it will copy each time which is not performance efficient.



*/




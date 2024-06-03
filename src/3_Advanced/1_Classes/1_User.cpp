#include "1_User.h"




// This way of declaring value in constructor is efficient , this way compiler creates and initialzie value in one go.
Rectangle::Rectangle(int width) : width{ width }, height{ width } {};

Rectangle::Rectangle(int width, int height)
{
    objectCount++;
    setWidth(width);
    setHeight(height);

}

// calling other constructors.To remove duplicates
Rectangle::Rectangle(int width, int height, const string& color) : Rectangle(width, height)
{
    cout << "Calling constructor with the color" << endl;
    this->color = color;

}


// copy contructor implementation
Rectangle::Rectangle(const Rectangle& source)
{
    cout << "Rectangle Copied" << endl;

    // BTW below code don't need to write compiler automatically generates for us , just for the deep copy have to found logic.
    this->width = source.width;
    this->height = source.height;
    // as we know string are like vector which makes deep copy on assignment.
    this->color = source.color;
}


Rectangle::~Rectangle()
{
    cout << "De-allocate any memory created on heap" << endl;
}

void Rectangle::draw()
{
    std::cout << "Drawing a Rectangle" << std::endl;
    cout << "Dimension: " << width << ", " << height << endl;
}

int Rectangle::getArea() const
{
    return width * height;
}

int Rectangle::getWidth() const
{
    return width;
}

int Rectangle::getHeight() const
{
    return this->height;
}

void Rectangle::setWidth(int width)
{
    if (width < 0)
        throw invalid_argument("width");

    this->width = width;
}

void Rectangle::setHeight(int height)
{
    if (height < 0) throw invalid_argument("height");

    this->height = height;
}


// always initialize the static members
int Rectangle::objectCount = 0;

int Rectangle::getObjectCount()
{
    return Rectangle::objectCount;
}







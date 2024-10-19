#include <iostream>
using namespace std;

class Shapes
{
public:
    // without using the virtual keyword in the base class, the base class's method will be called, even when you're calling the method on an object of the derived class through a base class pointer.
    void area()
    {
        cout << "Im in shape" << endl;
    }
    // Since the area() method in Shapes is not marked as virtual, C++ will use static binding, meaning the function call is resolved at compile time based on the type of the pointer (Shapes*), not the actual object it points to.
};

class Circle : public Shapes
{
public:
    void area()
    {
        cout << "Area is pi * r * r" << endl;
    }
};

class Square : public Shapes
{
public:
    void area()
    {
        cout << "Area is square of side" << endl;
    }
};

class Triangle : public Shapes
{
public:
    void area()
    {
        cout << "Area is 0.5 * h * b" << endl;
    }
};

int main()
{
    // Base class pointer pointing to derived class objects
    Shapes *shape = new Shapes();
    Shapes *circle = new Circle();
    Shapes *square = new Square();

    // This will now call the overridden method in the Circle class
    circle->area(); // Output: "Im in shape"
    square->area(); // Output: "Im in shape"

    delete shape;
    delete circle;
    delete square;
    return 0;
}
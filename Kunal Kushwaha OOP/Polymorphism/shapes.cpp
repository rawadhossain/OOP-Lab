#include <iostream>
using namespace std;

class Shapes
{
public:
    void area()
    {
        cout << "Im in shape" << endl;
    }
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
    circle->area(); // Output: "Area is pi * r * r"
    square->area(); // Output: "Area is square of side"

    delete shape;
    delete circle;
    delete square;
    return 0;
}
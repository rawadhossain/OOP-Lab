#pragma once

#include <iostream>
using namespace std;

class Box
{
private:
    double l; // Private variable (like the private l in Java)

public:
    double h;
    double w;

    // Static method (like in Java)
    static void greeting()
    {
        cout << "Hey, I am in Box class. Greetings!" << endl;
    }

    // Getter for private variable l (like getL() in Java)
    double getL() const
    {
        return l;
    }

    // Default constructor (equivalent to Box() in Java)
    Box()
    {
        this->h = -1;
        this->l = -1;
        this->w = -1;
    }

    // Constructor for a cube (equivalent to Box(double side) in Java)
    Box(double side)
    {
        this->l = side;
        this->h = side;
        this->w = side;
    }

    // Parameterized constructor (equivalent to Box(double l, double h, double w) in Java)
    Box(double l, double h, double w)
    {
        cout << "Box class constructor" << endl;
        this->l = l;
        this->h = h;
        this->w = w;
    }

    // Copy constructor (equivalent to Box(Box old) in Java)
    Box(const Box &old)
    {
        this->l = old.l;
        this->h = old.h;
        this->w = old.w;
    }
};

// int main()
// {
//     // Test the class
//     Box b1;
//     Box b2(3.0);           // Cube constructor
//     Box b3(1.0, 2.0, 3.0); // Parameterized constructor
//     Box b4(b3);            // Copy constructor

//     Box::greeting(); // Static method call

//     cout << "Box b3 dimensions: " << b3.getL() << ", " << b3.h << ", " << b3.w << endl;

//     return 0;
// }

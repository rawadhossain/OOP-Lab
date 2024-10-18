#pragma once

#include <iostream>
#include "Box.cpp"
#include "BoxWeight.cpp"
using namespace std;

// Derived class BoxPrice inheriting from BoxWeight
// BoxWeight class inheriting from Box
// Box -> BoxWeight -> BoxPrice

class BoxPrice : public BoxWeight
{
public:
    double cost;

    // Default constructor
    BoxPrice() : BoxWeight(), cost(-1) {}

    // Copy constructor
    BoxPrice(const BoxPrice &other) : BoxWeight(other), cost(other.cost) {}

    // Parameterized constructor
    BoxPrice(double l, double h, double w, double weight, double cost)
        : BoxWeight(l, h, w, weight), cost(cost) {}

    // Constructor for a cube with weight and cost
    BoxPrice(double side, double weight, double cost)
        : BoxWeight(side, weight), cost(cost) {}
};

int main()
{
    // Test the BoxPrice class
    BoxPrice bp1;
    BoxPrice bp2(1.0, 2.0, 3.0, 4.0, 5.0); // Full parameterized constructor
    BoxPrice bp3(3.0, 4.0, 100.0);         // Cube constructor with weight and cost
    BoxPrice bp4(bp2);                     // Copy constructor

    cout << "BoxPrice bp2 cost: " << bp2.cost << endl;
    cout << "BoxPrice bp3 cost: " << bp3.cost << endl;

    return 0;
}

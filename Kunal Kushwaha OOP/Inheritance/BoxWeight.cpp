#include <iostream>
#include <vector> // For std::vector
#include "Box.cpp"
using namespace std;

// Derived class BoxWeight inheriting from Box
class BoxWeight : public Box
{
public:
    double weight;

    // Default constructor
    BoxWeight() : weight(-1) {}

    // Overriding static method (although in C++ this is hiding, not overriding)
    static void greeting()
    {
        cout << "Hey, I am in BoxWeight class. Greetings!" << endl;
        vector<int> list;
    }

    // Copy constructor
    BoxWeight(const BoxWeight &other) : Box(other), weight(other.weight) {}

    // Constructor for a cube with weight
    BoxWeight(double side, double wt) : Box(side), weight(wt) {}

    // Parameterized constructor
    BoxWeight(double l, double h, double w, double wt) : Box(l, h, w), weight(wt) {}

    // Additional methods can be added as needed
};

// there are many variables in both parent and child classes
// you are given access to variables that are in the ref type i.e. BoxWeight
// hence, you should have access to weight variable
// this also means, that the ones you are trying to access should be initialised
// but here, when the obj itself is of type parent class, how will you call the constructor of child class
// this is why error
//        BoxWeight box6 = new Box(2, 3, 4);
//        System.out.println(box6);

int main()
{
    BoxWeight bw1;
    BoxWeight bw2(3.0, 5.0);           // Cube constructor
    BoxWeight bw3(1.0, 2.0, 3.0, 4.0); // Full parameterized constructor

    Box B(1, 2, 3);
    cout << B.h << endl;

    cout << B.getL() << endl;

    cout << bw3.weight << endl;
    BoxWeight bw4(bw3); // Copy constructor

    BoxWeight::greeting(); // Calls the static method from BoxWeight
    Box::greeting();       // Calls the static method from Box

    return 0;
}

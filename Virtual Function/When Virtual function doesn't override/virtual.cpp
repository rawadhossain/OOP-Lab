#include <iostream>
using namespace std;

// Normally, the function in the derived class overrides the virtual function in the base class.
/*
When does a derived class not override a virtual function?

When the derived class does not override a virtual function in the base class.
    -> No 'show()' function in derived class
    -> Different parameter in derived class
    -> marking "final" in base class function
*/

class Base
{
public:
    virtual void show() { cout << "Base class called\n"; } // normal function
};

class Derv1 : public Base
{
public:
    // No 'show()' function here, so it does not override.
};

class Derv2 : public Base
{
public:
    void show(int x)
    { // Different parameter, not an override
        cout << "Derv2 called\n";
    }
};

class BASE
{
public:
    virtual void show() final { cout << "BASE class called\n"; } // "final" => Prevent further overrides
};

class Derv3 : public BASE
{
public:
    void show()
    {
        cout << "Derv3 called\n";
    }
};

int main()
{
    Derv1 dv1; // object of derived class 1
    Derv2 dv2; // object of derived class 2
    Derv3 dv3; // object of derived class 3

    dv1.show(); // output: Base class called
    dv2.show(); // output: error, mismatch arguments
    dv3.show(); // output: // output: error, cannot override

    return 0;
}
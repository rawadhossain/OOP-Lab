#include <iostream>

using namespace std;

class Base
{
public:
    virtual void show() { cout << "Base class called\n"; } // normal function
};

class Derv1 : public Base
{
public:
    // void show() { cout << "Derv1 called\n"; }
};

class Derv2 : public Base
{
public:
    void show() { cout << "Derv2 called\n"; }
};

int main()
{
    Derv1 dv1; // object of derived class 1
    Derv2 dv2; // object of derived class 2
    Base *ptr; // pointer to base class

    dv1.show();
    ptr = &dv1;  // put address of dv1 in pointer
    ptr->show(); // execute show()

    // ptr = &dv2;  // put address of dv2 in pointer
    // ptr->show(); // execute show()

    return 0;
}
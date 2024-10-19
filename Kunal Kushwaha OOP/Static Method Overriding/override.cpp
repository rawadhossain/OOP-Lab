#include <iostream>
using namespace std;

/*
you cannot override static methods in C++ either. Just like in Java, static methods in C++ are class-level and not tied to individual instances of the class. This means that static methods are resolved at compile time based on the type of the reference or the class name,
not the actual object that is instantiated.

In C++, static methods are hidden in derived classes rather than overridden
*/
class Parent
{
public:
    static void display()
    {
        cout << "Parent static method" << endl;
    }
};

class Child : public Parent
{
public:
    static void display()
    {
        cout << "Child static method" << endl;
    }
};

int main()
{
    Parent::display(); // Calls Parent's static method
    Child::display();  // Calls Child's static method

    Parent *obj = new Child();
    obj->display(); // Calls Parent's static method due to static method resolution

    delete obj;
    return 0;
}

#include <iostream>
using namespace std;

class Main
{
public:
    // static is not dependent on objects of class
    static void fun()
    {
        // greeting(); // you cant use this because it requires an instance
        // but the function you are using it in does not depend on instances

        // you cannot access non static stuff without referencing their instances in
        // a static context

        // hence, here I am referencing it

        // fun() is static, greeting is non static, to use non static greeting in static fun an object has to be created for greeting
        // which is done by referencing to the object by the non static method(greeting)

        Main obj; // Creating an instance to call non-static member
        obj.greeting();
    }

    void fun2()
    {
        greeting();
    }

    // we know that something which is not static, belongs to an object
    void greeting()
    {
        // fun(); // it can call static func no problem
        //  non static method can call static method, but static can only call static member
        cout << "Hello world" << endl;
    }
};

int main()
{
    Main funn;
    funn.fun2(); // Call the non-static method fun2()

    return 0;
}

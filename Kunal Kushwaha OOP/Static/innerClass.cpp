#include <iostream>
#include <string>
using namespace std;

class InnerClasses
{
public:
    // Define a nested class inside the outer class
    class Test
    {
    public:
        string name;

        // Constructor for the Test class
        Test(const string &name) : name(name) {}

        // Override the toString() functionality
        string toString() const
        {
            return name;
        }
    };
};

int main()
{
    // Create objects of the nested class using the outer class name
    InnerClasses::Test a("Kunal");
    InnerClasses::Test b("Rahul");

    // Print the name using the toString() equivalent method
    cout << a.toString() << endl;

    // Uncomment to access the name directly (like in the commented-out Java code)
    // cout << a.name << endl;
    // cout << b.name << endl;

    return 0;
}

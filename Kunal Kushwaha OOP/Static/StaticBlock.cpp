#include <iostream>
using namespace std;

class StaticBlock
{
public:
    static int a;
    static int b;

    // Static initialization block in C++ can be done via a static method
    static void initialize()
    {
        cout << "I am in static block" << endl;
        b = a * 5;
    }
};

// Static variable initialization
int StaticBlock::a = 4;
int StaticBlock::b = 0; // This will be set in the initialize method

int main()
{
    // Calling static initialization block
    StaticBlock::initialize(); // This mimics the static block from Java

    StaticBlock obj;
    cout << StaticBlock::a << " " << StaticBlock::b << endl;

    StaticBlock::b += 3;
    cout << StaticBlock::a << " " << StaticBlock::b << endl;

    StaticBlock obj2;
    cout << StaticBlock::a << " " << StaticBlock::b << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Calculator
{
private:
    int num;

private:
    Calculator() : num(0) {}

    Calculator(int x) : num(x) {}

    ~Calculator()
    {
        cout << "Calculator object is destroyed." << endl;
    }

    int getValue()
    {
        return num;
    }

    void setValue(int x)
    {
        num = x;
    }

    void display()
    {
        cout << "Calculator display: " << num << endl;
    }

    void add(int x)
    {
        num += x;
        display();
    }

    void subtract(int x)
    {
        num -= x;
        display();
    }

    void multiply(int x)
    {
        num *= x;
        display();
    }

    int divideBy(int x)
    {
        if (x == 0)
            cout << "Undefined." << endl;
        else
            num /= x;

        return num % x;
        display();
    }

    void clear()
    {
        num = 0;
        display();
    }

    int main()
    {
        Calculator calc;
        calc.setValue(10);
        calc.add(10);
        calc.subtract(5);
        calc.multiply(3);
        calc.divideBy(2);
        calc.clear();

        return 0;
    }
};
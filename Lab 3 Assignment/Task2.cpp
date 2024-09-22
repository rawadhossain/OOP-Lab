#include <iostream>
#include <string>

using namespace std;

class Temperature
{
private:
    double value;
    string unit;

    bool ValidUnit(const string &unit)
    {
        return unit == "Celsius" || unit == "Fahrenheit" || unit == "Kelvin";
    }

    bool isAboveAbsoluteZero(double val, const string &unit)
    {
        if (unit == "Celsius")
            return val >= -273.15;
        if (unit == "Fahrenheit")
            return val >= -459.67;
        if (unit == "Kelvin")
            return val >= 0;
        return false;
    }

public:
    void assign(double val, const string &u)
    {
        if (!ValidUnit(u))
        {
            cout << "Invalid unit\n";
            return;
        }
        if (!isAboveAbsoluteZero(val, u))
        {
            cout << "below absolute zero is not allowed.\n";
            return;
        }
        value = val;
        unit = u;
    }

    double convert(const string &target)
    {
        if (!ValidUnit(target))
        {
            cout << "Invalid unit\n";
            return -1;
        }

        double temp;
        if (unit == "Celsius")
        {
            temp = value;
        }
        else if (unit == "Fahrenheit")
        {
            temp = (value - 32) * 5 / 9;
        }
        else
        {
            temp = value - 273.15;
        }

        if (target == "Celsius")
        {
            return temp;
        }
        else if (target == "Fahrenheit")
        {
            return temp * 9 / 5 + 32;
        }
        else
        {
            return temp + 273.15;
        }
    }

    void print()
    {
        cout << "The temperature is " << value << " " << unit << ".\n";
    }
};

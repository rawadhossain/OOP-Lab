#include "counter.h"
#include <iostream>

using namespace std;

Counter::Counter() : count(0), incre_Step(1) {}

Counter::Counter(const int stepValue) : count(0)
{
    if (stepValue < 0)
        incre_Step = 1;
    else
        incre_Step = stepValue;
}

Counter::~Counter() {}

void Counter::setIncrementStep(const int stepValue)
{
    if (stepValue > 0)
        incre_Step = stepValue;
    else
        cout << "Negative value not allowed." << endl;
}

int Counter::getCount() const
{
    return count;
}

void Counter::increment()
{
    count += incre_Step;
}

void Counter::resetCount()
{
    count = 0;
}

Counter Counter::operator+(const Counter &c2) const
{
    if (incre_Step == c2.incre_Step)
    {
        Counter c;
        if (count > c2.count)
            c = count;
        else
            c = c2.count;

        c.count = count + c2.count;
        return c;
    }

    else
        cout << "Increment step values are not same" << endl;
}

Counter Counter::operator+=(const Counter &c2)
{
    Counter c(count > c2.count ? count : c2.count);
    c.count = count + c2.count;
    return c;
}

Counter Counter::operator++()
{
    return Counter(++count);
}

Counter Counter::operator++(int)
{
    return Counter(count++);
}

bool Counter::operator>(const Counter &c2)
{
    return count > c2.count ? true : false;
}

bool Counter::operator<(const Counter &c2)
{
    return count < c2.count ? true : false;
}

bool Counter::operator>=(const Counter &c2)
{
    return count >= c2.count ? true : false;
}

bool Counter::operator<=(const Counter &c2)
{
    return count <= c2.count ? true : false;
}

bool Counter::operator==(const Counter &c2)
{
    return count == c2.count ? true : false;
}

bool Counter::operator!=(const Counter &c2)
{
    return count != c2.count ? true : false;
}

int main()
{
    Counter c1;
    cout << "C1 count: " << c1.getCount() << endl;
    c1++;
    cout << "C1 count: " << c1.getCount() << endl;

    Counter c2;
    Counter c3;
    c2++;
    ++c3;
    c3++;
    c2 += c3;
    cout << "C2 count: " << c2.getCount() << endl;
    cout << "C3 count: " << c3.getCount() << endl;

    return 0;
}
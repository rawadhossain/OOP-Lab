#include <iostream>
using namespace std;

class Counter
{
private:
    int count;
    int step;

public:
    void setIncrementStep(int val)
    {
        step = val;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count += step;
    }
    void resetCount()
    {
        count = 0;
    }
};

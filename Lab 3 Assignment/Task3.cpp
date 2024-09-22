#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}

    int hours()
    {
        return hour;
    }

    int minutes()
    {
        return minute;
    }

    int seconds()
    {
        return second;
    }

    void reset(int h, int m, int s)
    {
        hour = h % 24;
        minute = m % 60;
        second = s % 60;
    }

    void advance(int h, int m, int s)
    {
        second += s;
        minute += m + second / 60;
        hour += h + minute / 60;
        second %= 60;
        minute %= 60;
        hour %= 24;
    }

    void print()
    {
        cout << setfill('0') << setw(2) << hour << ":"
             << setfill('0') << setw(2) << minute << ":"
             << setfill('0') << setw(2) << second << endl;
    }
};
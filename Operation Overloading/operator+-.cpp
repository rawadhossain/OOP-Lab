#include <iostream>
#include <string>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {} // Default constructor

    Point(int x, int y) : x(x), y(y) {} // parameterized constructor

    // in one line
    // Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point &p)
    {
        // Point obj;
        // obj.x = x + p.x;
        // obj.y = y + p.y;
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p)
    {
        Point obj;
        obj.x = x - p.x;
        obj.y = y - p.y;
        return obj;
    }

    // same thing just, an object is passed through another obj to find the sum
    Point add(const Point &p)
    {
        Point obj;
        obj.x = x + p.x;
        obj.y = y + p.y;
        return obj;
    }

    Point operator*(const Point &p)
    {
        Point obj;
        obj.x = x * p.x;
        obj.y = y * p.y;
        return obj;
    }

    void display()
    {
        cout << "x: " << x << " , " << "y: " << y << endl;
    }
};

int main()
{
    Point p1(10, 5), p2(2, 1);
    Point p3 = p1 + p2;
    p3.display();

    // Point p4 = p1 - p2;
    // p4.display();

    // Point p5 = p1.add(p2);
    // p5.display();

    // //(x + y) * (x - y)

    // Point p6 = (p1.add(p2)) * (p1.add(p2));
    // p6.display();

    return 0;
}
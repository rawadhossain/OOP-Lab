#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class Coordinate
{
private:
    float abscissa;
    float ordinate;

public:
    Coordinate() : abscissa(0), ordinate(0) {}
    Coordinate(float x, float y) : abscissa(x), ordinate(y) {}
    ~Coordinate() {}

    void display() const;
    float operator-(const Coordinate &c) const;
    float getDistance() const;

    void move_x(float val);
    void move_y(float val);
    void move(float x_val, float y_val);

    bool operator>(const Coordinate &c) const;
    bool operator<(const Coordinate &c) const;
    bool operator>=(const Coordinate &c) const;
    bool operator<=(const Coordinate &c) const;
    bool operator==(const Coordinate &c) const;
    bool operator!=(const Coordinate &c) const;
};

#endif
#include "coordinate.h"
#include <iostream>
#include <cmath>

using namespace std;

void Coordinate::display() const
{
    cout << "abscissa: " << abscissa << " " << "Ordinate: " << ordinate << endl;
}

float Coordinate::operator-(const Coordinate &c) const
{
    return sqrt(pow(abscissa - c.abscissa, 2) + pow(ordinate - c.ordinate, 2));
}

float Coordinate::getDistance() const
{
    return sqrt(pow(abscissa, 2) + pow(ordinate, 2));
}

void Coordinate::move_x(float val)
{
    abscissa += val;
}

void Coordinate::move_y(float val)
{
    ordinate += val;
}

void Coordinate::move(float x_val, float y_val)
{
    abscissa += x_val;
    ordinate += y_val;
}

bool Coordinate::operator>(const Coordinate &c) const
{
    return (getDistance() > c.getDistance()) ? true : false;
}

bool Coordinate::operator<(const Coordinate &c) const
{
    return getDistance() < c.getDistance() ? true : false;
}

bool Coordinate::operator>=(const Coordinate &c) const
{
    return getDistance() >= c.getDistance() ? true : false;
}

bool Coordinate::operator<=(const Coordinate &c) const
{
    return getDistance() <= c.getDistance() ? true : false;
}

bool Coordinate::operator==(const Coordinate &c) const
{
    return getDistance() == c.getDistance() ? true : false;
}

bool Coordinate::operator!=(const Coordinate &c) const
{
    return getDistance() != c.getDistance() ? true : false;
}
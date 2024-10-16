#ifndef COUNTER_H
#define COUNTER_H

#pragma once
#include <iostream>

class Counter
{

private:
    int count;
    int incre_Step;

public:
    Counter();
    Counter(const int stepValue);
    ~Counter();
    void setIncrementStep(const int stepValue);
    int getCount() const;
    void increment();
    void resetCount();
    Counter operator+(const Counter &c) const;
    Counter operator+=(const Counter &c);
    Counter operator++();
    Counter operator++(int);

    bool operator>(const Counter &c);
    bool operator<(const Counter &c);
    bool operator>=(const Counter &c);
    bool operator<=(const Counter &c);
    bool operator==(const Counter &c);
    bool operator!=(const Counter &c);
};

#endif
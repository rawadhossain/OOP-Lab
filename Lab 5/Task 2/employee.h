#pragma once
#include <string>

using namespace std;

class Employee
{
private:
    string name;
    int dob;
    int salary;

public:
    void setName(string name);
    string getName();
    void setDOB(int year);
    int getDOB();
    void setSalary(int salary);
    int getSalary();

    void setInfo(string N, int year, int salary);
    void getInfo();
    bool compareAge(Employee &e);
};
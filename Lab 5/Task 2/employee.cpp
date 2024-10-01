#include <iostream>
#include "employee.h"
#include <string>

using namespace std;

static const int current = 2024;

void Employee::setName(string N)
{
    if (N.length() > 2)
        name = N;
    else
        name = "John Doe";
}

string Employee::getName()
{
    return name;
}

void Employee::setDOB(int year)
{
    if (current - year < 18)
        dob = {2002};
    else
        dob = {year};
}

int Employee::getDOB()
{
    return dob;
}

void Employee::setSalary(int sal)
{
    if (sal <= 100000 && sal >= 10000)
        salary = sal;
    else
        salary = 10000;
}

int Employee::getSalary()
{
    return salary;
}

void Employee::setInfo(string n, int y, int s)
{
    setName(n);
    setDOB(y);
    setSalary(s);
}

void Employee::getInfo()
{
    cout << "Name: " << getName() << endl;
    cout << "Date of Birth: " << getDOB() << endl;
    cout << "Salary: BDT " << getSalary() << endl;
}

bool Employee::compareAge(Employee &e)
{
    return (dob < e.dob);
}

int main()
{
    Employee emp1, emp2;

    emp1.setInfo("ABCD", 2001, 30000);
    emp2.setInfo("EFGH", 1995, 50000);

    emp1.getInfo();
    emp2.getInfo();

    if (emp1.compareAge(emp2))
        cout << "Employee 1 is older than Employee 2" << endl;
    else
        cout << "Employee 2 is older than Employee 1" << endl;

    return 0;
}
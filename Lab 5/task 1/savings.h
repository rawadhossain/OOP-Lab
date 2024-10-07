#pragma once
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include <string>
#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    string accountName;
    string holderName;
    string address;
    double annualInterestRate;
    double currentBalance;
    double minimumBalance;
    static double Interest;

public:
    SavingsAccount() : minimumBalance(0), currentBalance(0), annualInterestRate(0) {}

    string getAccountName();
    void setAccountName(string aName);

    string getHolderName();
    void setHolderName(string hName);

    string getAddress();
    void setAddress(string aAddress);

    double getAnnualInterestRate();
    void setAnnualInterestRate(double interestRate);
    double getInterestRate();

    double getCurrentBalance();
    void setCurrentBalance(double currBalance);

    double getMinimumBalance();
    void setMinimumBalance(double minBalance);

    void deposit(double value);
    void withdraw(double value);

    void disburseInterest(int periodInMonths);
};

#endif
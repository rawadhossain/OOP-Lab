#include "savings.h"
#include <string>

string SavingsAccount::getAccountName()
{
    return accountName;
}

void SavingsAccount::setAccountName(string aName)
{
    accountName = aName;
}

string SavingsAccount::getHolderName()
{
    return holderName;
}

void SavingsAccount::setHolderName(string hName)
{
    holderName = hName;
}

string SavingsAccount::getAddress()
{
    return address;
}

void SavingsAccount::setAddress(string aAddress)
{
    address = aAddress;
}

double SavingsAccount::getAnnualInterestRate()
{
    return annualInterestRate;
}

void SavingsAccount::setAnnualInterestRate(double interestRate)
{
    annualInterestRate = interestRate;
    Interest += interestRate;
}

double SavingsAccount::getInterestRate()
{
    return Interest;
}

double SavingsAccount::getCurrentBalance()
{
    return currentBalance;
}

void SavingsAccount::setCurrentBalance(double currBalance)
{
    currentBalance = currBalance;
}

double SavingsAccount::getMinimumBalance()
{
    return minimumBalance;
}

void SavingsAccount::setMinimumBalance(double minBalance)
{
    minimumBalance = minBalance;
}

void SavingsAccount::deposit(double value)
{

    setCurrentBalance(getCurrentBalance() + value);
}

void SavingsAccount::withdraw(double value)
{
    setCurrentBalance(getCurrentBalance() - value);
}

void SavingsAccount::disburseInterest(int periodInMonths)
{
    setCurrentBalance(getCurrentBalance() + getCurrentBalance() * getAnnualInterestRate());
    setMinimumBalance(getCurrentBalance());
}

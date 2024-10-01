#include <iostream>
using namespace std;

class BankAccount
{
private:
    int acc_num;
    string acc_name;
    bool savings;
    int currentBalance;
    const int minBalance;
    int interest;
    static int totalAccCreated, totalAccPresent, totalTax;

public:
    BankAccount(int min) : acc_num(0), currentBalance(0), interest(3), minBalance(min)
    {
        totalAccCreated++;
        totalAccPresent++;
    }

    ~BankAccount()
    {
        cout << "Account of " << acc_name << ", Account number " << acc_num << ", Destroyed with a Balance of BDT " << currentBalance << endl;
        totalAccPresent--;
    }

    static int gettotalAccCreated()
    {
        return totalAccCreated;
    }

    static int gettotalAccPresent()
    {
        return totalAccPresent;
    }

    static int gettotalTax()
    {
        return totalTax;
    }

    int getBalance() const
    {
        return currentBalance;
    }

    void setBalance(int value)
    {
        currentBalance = value;
    }

    void setBankDetails(int AccNum, string name, bool savings, int balance)
    {
        acc_num = AccNum;
        acc_name = name;
        savings = savings;
        currentBalance = balance;
    }

    void setinterest(int value)
    {
        interest = value;
    }

    void showBankDetails()
    {
        cout << "Account Number: " << acc_num << endl;
        cout << "Account Holder: " << acc_name << endl;
        cout << "Account Type: ";
        if (savings)
            cout << "Savings" << endl;
        else
            cout << "Current" << endl;
        cout << "Current Balance: " << currentBalance << endl;
        cout << "Minimum Balance: " << minBalance << endl;
    }

    void showBalance()
    {
        cout << "Account Balance: " << currentBalance << endl;
    }

    void deposit(int value)
    {
        if (value < 0)
            cout << "Invalid" << endl;
        else
            setBalance(value + currentBalance);
    }

    void withdraw(int value)
    {
        if (value <= 0 || (currentBalance - value) < minBalance)
            cout << "Invalid" << endl;
        else
            setBalance(currentBalance - value);
    }

    void giveInterest()
    {
        int dep = (interest * currentBalance) / 100;
        totalTax += (dep) / 10;
        deposit(9 * dep / 10);
    }
};

int BankAccount::totalAccCreated = 0;
int BankAccount::totalAccPresent = 0;
int BankAccount::totalTax = 0;

void display_stat()
{
    cout << "Total created: " << BankAccount::gettotalAccCreated() << endl;
    cout << "Total Present: " << BankAccount::gettotalAccPresent() << endl;
    cout << "Total TAX: " << BankAccount::gettotalTax() << endl;
}

BankAccount Larger(const BankAccount A, const BankAccount B)
{
    if (A.getBalance() > B.getBalance())
        return A;
    return B;
}

int main()
{
    BankAccount account_1(100);
    account_1.showBankDetails();
    account_1.setBankDetails(4554, "ABCD", true, 4243);
    account_1.showBankDetails();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// Abstract Class for Bank Account
class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Pure virtual functions - shows only the essential details
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    // Method to get balance (abstraction in saction)
    virtual double getBalance() const = 0;
};

// Encapsulation using access modifiers in Derived Class
class SavingsAccount : public BankAccount
{
private:
    string accountHolder;

public:
    // Constructor that sets up account holder and initial balance
    SavingsAccount(string name, double initialBalance) : BankAccount(initialBalance), accountHolder(name) {}

    // Implementing abstract methods
    void deposit(double amount) override
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $" << amount << " to " << accountHolder << "'s account." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) override
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " from " << accountHolder << "'s account." << endl;
        }
        else
        {
            cout << "Invalid or insufficient funds for withdrawal." << endl;
        }
    }

    // Getter for balance - encapsulated by using access modifiers
    double getBalance() const override
    {
        return balance;
    }

    // Getter for account holder's name
    string getAccountHolder() const
    {
        return accountHolder;
    }
};

// Main function demonstrating both Abstraction and Encapsulation
int main()
{
    // Create a SavingsAccount object - only showing essential information
    SavingsAccount myAccount("John Doe", 500.0);

    // Using methods without knowing internal details (abstraction)
    cout << "Account Holder: " << myAccount.getAccountHolder() << endl;
    cout << "Initial Balance: $" << myAccount.getBalance() << endl;

    // Deposit and withdraw operations
    myAccount.deposit(200.0);
    myAccount.withdraw(100.0);

    // Display final balance
    cout << "Final Balance: $" << myAccount.getBalance() << endl;

    return 0;
}

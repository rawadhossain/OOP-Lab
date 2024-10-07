#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

#include "savings.h"

void editInformationByKeyboard(SavingsAccount acc)
{
    string buff;
    double num;

    cout << "Acccount name: ";
    getline(cin, buff);
    acc.setAccountName(buff);

    cout << "Holder name: ";
    getline(cin, buff);
    acc.setHolderName(buff);

    string add;
    cout << "Enter Address: ";
    while (true)
    {
        getline(cin, buff);
        if (buff == "-1")
            break;
        add += buff;
        add += "\n";
    }
    acc.setAddress(add);

    cout << "Enter Balance: ";
    cin >> num;
    acc.setCurrentBalance(num);

    cout << "Interest rate (input): ";
    cin >> num;
    acc.setAnnualInterestRate(num);
    cin.ignore();
}

string generateString()
{
    string word = "";
    int r = (rand() % 7) + 4;
    for (int i = 0; i < r; i++)
    {
        int k = rand() % 26;
        word += k + 'a';
    }
    return word;
}

double generateInterest()
{
    int r = (rand() % 3) + 2;
    int n = rand() % 10;
    return (r + (n / 10.0));
}

void generateInformationRandom(SavingsAccount &acc)
{
    acc.setAccountName(generateString() + " " + generateString());

    acc.setHolderName(generateString() + " " + generateString());

    acc.setAddress(generateString() + " " + generateString() + " " + generateString() + " " + generateString() + " " + generateString());

    acc.setAnnualInterestRate(generateInterest());

    acc.setCurrentBalance((rand() % 49000) + 1000);
}

int ShowInterestAll(SavingsAccount ar[])
{
    cout << "TOTAL INTEREST: " << ar[0].getInterestRate() << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << "ACCOUNT " << i << ": " << ar[i].getAnnualInterestRate() << endl;
    }
    string choice;
    cout << "DISBURSE INTEREST? (YES/NO) ";
    cin >> choice;
    if (choice == "YES")
    {
        for (int i = 0; i < 100; i++)
        {
            ar[i].disburseInterest(1);
        }
    }
}

void ShowAllAlphabetically(SavingsAccount ar[])
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = i; j < 100 - i - 1; j++)
        {
            if (strcmp(&ar[j].getAccountName()[0], &ar[j + 1].getAccountName()[0]) > 0)
            {
                SavingsAccount temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        cout << ar[i].getAccountName() << " " << ar[i].getCurrentBalance() << endl;
    }
}

double SavingsAccount::Interest = 0.0;

int main()
{
    srand(time(0));
    SavingsAccount acc[100];

    // editInformationByKeyboard(acc[0]);
    // editInformationByKeyboard(acc[1]);

    generateInformationRandom(acc[0]);
    generateInformationRandom(acc[1]);
    generateInformationRandom(acc[2]);
    generateInformationRandom(acc[3]);
    generateInformationRandom(acc[4]);
    generateInformationRandom(acc[5]);
    generateInformationRandom(acc[6]);
    generateInformationRandom(acc[7]);
    generateInformationRandom(acc[8]);
    acc[1].setAnnualInterestRate(5.2);
    // cout << acc[0].getAccountName() << endl << acc[0].getHolderName() << endl;
    // cout << acc[0].getAddress() << endl << acc[0].getAnnualInterestRate() << endl << acc[0].getCurrentBalance() << endl;

    // ShowInterestAll(acc);

    ShowAllAlphabetically(acc);

    return 0;
}

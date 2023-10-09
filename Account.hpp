#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Account
{
private:
    uint16_t accountNumber;
    string firstName;
    string lastName;
    float balance;
    static uint16_t NextAccountNumber;
public:
    Account(){};
    Account(string firstName, string lastName, float balance);
    uint16_t getAccountNumber(){return accountNumber;};
    string getFirstName(){return firstName;};
    string getLastName(){return lastName;};
    float getBalance(){return balance;};

    void Deposit(float amount);
    void Withdraw(float amount);
    static void getLastAccountNumber() {return NextAccountNumber;};
    static void setLastAccountNumber(uint16_t accountNumber);
    friend ostream& operator<<(ostream& os, Account& account);
    friend ifstream& operator>>(ifstream& ifs, Account& account);
    friend ofstream& operator<<(ofstream& ofs, Account& account);

    ~Account();
};

long Account::NextAccountNumber = 0;

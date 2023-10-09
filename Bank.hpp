#include <stdio.h>
#include <string>
#include <map>
using namespace std;
class Bank{
private:
    string bankName;
    string bankAddress;
    string bankPhoneNumber;
    map<uint16_t, Account> accounts;
public:
    Bank(){};
    Bank(string bankName, string bankAddress, string bankPhoneNumber);
    string getBankName(){return bankName;};
    string getBankAddress(){return bankAddress;};
    string getBankPhoneNumber(){return bankPhoneNumber;};

    Account openAccount(string firstName, string lastName, float balance);
    void deleteAccount(uint16_t accountNumber);
    Account getAccount(uint16_t accountNumber);
    Account withdraw(uint16_t accountNumber, float amount);
    Account deposit(uint16_t accountNumber, float amount);
    void showAllAccounts();
    ~Bank();
};

#include "Account.hpp"

Account::Account(string firstName, string lastName, float balance){
    accountNumber = ++NextAccountNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->balance = balance;
}

Account::~Account(){
    cout<<"Account number: "<<accountNumber<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Balance: "<<balance<<endl;
}

void Account::Deposit(float amount){
    balance += amount;
}

void Account::Withdraw(float amount){
    balance -= amount;
}

void Account::setLastAccountNumber(uint16_t accountNumber){
    NextAccountNumber = accountNumber;
}

ostream& operator<<(ostream& os, Account& account){
    os<<"Account Number: "<<account.getAccountNumber()<<endl;
    os<<"First Name: "<<account.getFirstName()<<endl;
    os<<"Last Name: "<<account.getLastName()<<endl;
    os<<"Balance: "<<account.getBalance()<<endl;
    return os;
}

ifstream& operator>>(ifstream& ifs, Account& account){
    ifs>>account.accountNumber;
    ifs>>account.firstName;
    ifs>>account.lastName;
    ifs>>account.balance;
    return ifs;
}

ofstream& operator<<(ofstream& ofs, Account& account){
    ofs<<account.accountNumber<<endl;
    ofs<<account.firstName<<endl;
    ofs<<account.lastName<<endl;
    ofs<<account.balance<<endl;
    return ofs;
}

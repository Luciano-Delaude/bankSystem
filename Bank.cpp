#include "Bank.hpp"

Bank::Bank(string bankName, string bankAddress, string bankPhoneNumber){
    this->bankName = bankName;
    this->bankAddress = bankAddress;
    this->bankPhoneNumber = bankPhoneNumber;
}

Bank::Bank()
{
    Account account;
    ifstream inputfile;
    inputfile.open("Accounts.txt");
    if(!inputfile){
        cout<<"File not found"<<endl;
        return;
    }
    while(!inputfile.eof()){
        inputfile>>account;
        accounts.insert(pair<uint16_t, Account>(account.getAccountNumber(), account));
    }
    Account::setLastAccountNumber(account.getAccountNumber())
    inputfile.close();
}

Account Bank::openAccount(string firstName, string lastName, float balance){
    ofstream outputfile;
    Account account(firstName, lastName, balance);
    accounts.insert(pair<uint16_t, Account>(account.getAccountNumber(), account));
    outputfile.open("Accounts.txt", ios::trunc);
    for (auto it = accounts.begin(); it != accounts.end(); it++){
        outputfile<<it->second;
    }
    outputfile.close();
    return account;
}

void Bank::deleteAccount(uint16_t accountNumber){
    map<uint16_t, Account>::iterator it = accounts.find(accountNumber);
    cout<<"Account deleted"<<it->second<<endl;
    accounts.erase(it);
}

Account Bank::getAccount(uint16_t accountNumber){
    map<uint16_t, Account>::iterator it = accounts.find(accountNumber);
    return it->second;
}

Account Bank::deposit(uint16_t accountNumber, float amount){
    map<uint16_t, Account>::iterator it = accounts.find(accountNumber);
    it->second.Deposit(amount);
    return it->second;
}

Account Bank::withdraw(uint16_t accountNumber, float amount){
    map<uint16_t, Account>::iterator it = accounts.find(accountNumber);
    it->second.Withdraw(amount);
    return it->second;
}

void Bank::showAllAccounts(){
    map<uint16_t, Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++){
        cout<<"Account number: "<<it->first<<endl;
        cout<<it->second<<endl;
    }
}

Bank::~Bank(){
    ofstream outputfile;
    outputfile.open("Accounts.txt", ios::trunc);
    
    map<uint16_t, Account>::iterator it;
    for (auto it = accounts.begin(); it != accounts.end(); it++){
        outputfile<<it->second;
    }
    outputfile.close();
}
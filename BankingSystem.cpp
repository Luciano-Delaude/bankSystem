#include "Account.hpp"
#include "Bank.hpp"
int main(){
    Account account;
    Bank bank;
    float amount;
    uint16_t accountNumber;
    int choice;
    string firstName;
    string lastName;
    float balance;

    cout<<"***BANKING SYSTEM***"<<endl;
    cout<<"1. Open an Account"<<endl;
    cout<<"2. Balance Enquiry"<<endl;
    cout<<"3. Deposit"<<endl;
    cout<<"4. Withdrawal"<<endl;
    cout<<"5. Close an Account"<<endl;
    cout<<"6. Show All Accounts"<<endl;
    cout<<"7. Exit"<<endl;

    do
    {
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout>>"Enter your first name: ";
                cin>>firstName;
                cout<<"Enter your last name: ";
                cin>>lastName;
                cout<<"Enter your balance: ";
                cin>>balance;
                account = bank.openAccount(firstName, lastName, balance);
                cout<<"Your account number is: "<<account.getAccountNumber()<<endl;
                cout<<account;
                break;
            case 2:
                cout<<"Enter your account number: ";
                cin>>accountNumber;
                account = bank.getAccount(accountNumber);
                cout<<"The information of the account is: "<<endl;
                cout<<account;
                break;
            case 3:
                cout<<"Enter your account number: ";
                cin>>accountNumber;
                cout<<"Enter the amount to deposit: ";
                cin<<amount;
                account = bank.deposit(accountNumber, amount);
                cout<<"The new information of the account is: "<<endl;
                cout<<account;
                break;
            case 4:
                cout<<"Enter your account number: ";
                cin>>accountNumber;
                cout<<"Enter the amount to withdraw: ";
                cin<<amount;
                account = bank.withdraw(accountNumber, amount);
                cout<<"The new information of the account is: "<<endl;
                cout<<account;
                break;
            case 5:
                cout<<"Enter your account number: ";
                cin>>accountNumber;
                bank.deleteAccount(accountNumber);
                cout<<"Account deleted succesfully."<<endl;
                break;
            case 6:
                cout<<showAllAccounts();
                break;
            case 7:
                break;
            default:
                cout<<"Invalid choice, please insert a valid option"<<endl;
                exit(0);
        }
    } while (choice != 7);
    
    return 0;
}

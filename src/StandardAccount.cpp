#include "StandardAccount.h"

Standard_Account::Standard_Account(
    const string& first_name,
    const string& last_name,
    const string& id,
    const string& pin,
    const string& address,
    const string& phone,
    Account_type type,
    double balance)
    : Account(first_name, last_name, id, pin,
              address, phone, type, balance) {}
Standard_Account::Standard_Account(
    const Account* copied,
    string PIN,
    Account_type newtype,
    double balance)
    : Account(copied, PIN, newtype, balance) {}

bool Standard_Account::withdraw(double withdrawal){
    if (verifyPin()) {
        if (withdrawal <= 0 || withdrawal > balance) {
            cout << "Operation error: Invalid withdrawal amount.\n";
            return false;
        }
        if(withdrawal>withdrawal_limit){
            cout<<"Invalid withdrawal amount, Standard accounts can withdraw a maximum amount of 10,000.\n";
            return false;
        }
        balance -= withdrawal;
        transactions.push_back(to_string(withdrawal) + " pounds were withdrawn.");
        return true;
    }
    cout << "Incorrect PIN.\n";
    return false;
}
bool Standard_Account::deposit(double deposit){
    if (verifyPin()) {
        if (deposit <= 0) {
            cout << "Operation error: Invalid dep amount.\n";
            return false;
        }
        if(deposit>deposit_limit){
            cout<<"Invalid deposit amount. Standard accounts can deposit a maximum amount of 10,000 per time.\n";
            return false;
        }
        if( (deposit+balance) > balance_limit){
            cout<<"Operation exceeds balance limit. Standard accounts have limit of 1,000,000.\n";
            return false;
        }
        balance += deposit;
        transactions.push_back(to_string(deposit) + " pounds were deposited.");
        return true;
    }
    cout << "Incorrect PIN.\n";
    return false;
}
bool Standard_Account::transfer_to(Standard_Account &receiver , double amount){
    if (!verifyPin()) {
        cout << "Transfer failed. Incorrect PIN.\n";
        return false;
    }
    if (amount <= 0) {
        cout << "Transfer failed. Invalid amount.\n";
        return false;
    }
    if (amount > balance) {
        cout << "Transfer failed. Insufficient balance.\n";
        return false;
    }
    if (amount > transfer_limit){
        cout<<"Transfer failed. Exceeds transfer limit.\n";
        return false;
    }
    if(amount+receiver.balance > receiver.balance_limit){
        cout<<"Transfer failed. Exceeding receiver balance limit.\n";
        return false;
    }
    if(amount>receiver.transfer_limit){
        cout<<"Transfer failed. Exceeding receiver receiving limit.\n";
        return false;
    }
    balance -= amount;
    receiver.balance += amount;
    receiver.transactions.push_back(to_string(amount) + " pounds were recieved from " + first_name + " " + last_name + ".\n");
    transactions.push_back(to_string(amount) + " pounds were transfered to " + receiver.first_name + " " + receiver.last_name +".\n");
    cout << "Transaction completed successfully.\n";
    return true;
}
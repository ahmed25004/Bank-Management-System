#include "SavingsAccount.h"
#include "StandardAccount.h"

Savings_Account::Savings_Account(
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

Savings_Account::Savings_Account(
    const Account* copied,
    string PIN,
    Account_type newtype,
    double balance)
    : Account(copied, PIN, newtype, balance) {}

bool Savings_Account::transfer_to(Standard_Account& receiver, double amount) {
    cout << "Transfers are not allowed from a Saving Account.\n";
    return false;
}

bool Savings_Account::apply_interest() {
    double interest = balance * interest_rate;
    if (balance + interest > balance_limit) {
        cout << "Interest not applied: balance would exceed the limit.\n";
        return false;
    }
    balance += interest;
    transactions.push_back("Interest 6% is applied: " + to_string(interest) + "\nTotal balance is " + to_string(balance));
    cout << "Interest of " << interest << " applied successfully.\n";
    return true;
}

bool Savings_Account::withdraw( double withdrawal){
    if (verifyPin()) {
        if (withdrawal <= 0 || withdrawal > balance) {
            cout << "Operation error: Invalid withdrawal amount.\n";
            return false;
        }
        balance -= withdrawal;
        transactions.push_back(to_string(withdrawal) + " pounds were withdrawn.");
        return true;
    }
    cout << "Incorrect PIN.\n";
    return false;
}

bool Savings_Account::deposit(double deposit){
    if (verifyPin()) {
        if (deposit <= 0) {
            cout << "Operation error: Invalid dep amount.\n";
            return false;
        }
        if( (deposit+balance) > balance_limit){
            cout<<"Operation exceeds balance limit. Savings accounts have limit of 10,000,000.\n";
            return false;
        }
        balance += deposit;
        transactions.push_back(to_string(deposit) + " pounds were deposited.");
        return true;
    }
    cout << "Incorrect PIN.\n";
    return false;
}
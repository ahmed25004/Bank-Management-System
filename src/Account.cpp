#include "Account.h"
#include "Utils.h"

//Constructor
Account::Account(string fname, string lname, string id,
                 string PIN, string address, string phone_number,
                 Account_type accountType, double balance)
    : first_name(fname),
      last_name(lname),
      ID(id),
      PIN(PIN),
      address(address),
      phone_number(phone_number),
      account_type(accountType),
      balance(balance) {}

Account::Account(const Account* copied, string PIN,
                 Account_type newtype, double balance)
    : first_name(copied->first_name),
      last_name(copied->last_name),
      ID(copied->ID),
      PIN(PIN),
      account_type(newtype),
      address(copied->address),
      phone_number(copied->phone_number) {}


//method to take PIN from user to access operation and compare it to user's true PIN
bool Account::verifyPin() const {
    string tempPIN;
    cout << "Please enter PIN : ";
    cin >> tempPIN;
    return PIN == tempPIN;
}

//method to return account type as a string to print it when wanted
string Account::type_to_string()const{
    switch (account_type) {
        case Standard:
            return "Standard";
        case Savings:
            return "Savings";
        case Business:
            return "Business";
        default:
            return "Not clarified";
    }
}

//methods related to money:
bool Account::withdraw(double withdrawal) {
    if (verifyPin()) {
        if (withdrawal <= 0 || withdrawal > balance) {
            cout << "Operation error: Invalid withdrawal amount.\n";
            return false;
        }
        balance -= withdrawal;
        transactions.push_back(to_string(withdrawal) + " pounds were withdrawn.\n");
        return true;
    }
    cout << "Incorrect PIN.\n";
    return false;
}
bool Account::deposit(double dep) {
    if (verifyPin()) {
        if (dep <= 0) {
            cout << "Operation error: Invalid dep amount.\n";
            return false;
        }
        balance += dep;
        transactions.push_back(to_string(dep) + " pounds were deposited.\n");
        return true;
    }
    cout << "Incorrect PIN.\n";
    return false;
}
bool Account::check_balance() const {
    if (verifyPin()) {
        cout << "Your current balance is " << balance << " pounds.\n";
        return true;
    }
    cout << "Incorrect PIN.\n";
    return false;
}
bool Account::transfer_to(Account &receiver , double amount) {
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
    balance -= amount;
    receiver.balance += amount;
    transactions.push_back(
            to_string(amount) + " pounds were transferred to " + receiver.first_name + " " + receiver.last_name +
            ".\n");
    receiver.transactions.push_back(
            to_string(amount) + " pounds were received from " + first_name + " " + last_name + ".\n");
    cout << "Transaction completed successfully.\n";
    return true;
}

//methods related to changing information (PIN, address, number)
bool Account::change_address(const string &new_address) {
    if (verifyPin()) {
        address = new_address;
        cout << "Address changed successfully.\n";
        return true;
    }
    cout <<"=================\n"
           "! Access denied !\n"
           "=================\n";
    return false;
}
bool Account::change_PIN() {
    if (verifyPin()) {
        PIN = PINcreation();
        cout << "Your PIN has been changed successfully.\n";
        return true;
    }
    cout <<"=================\n"
           "! Access denied !\n"
           "=================\n";
    return false;
}
bool Account::change_phone_number(const string &new_phone_number) {
    if (verifyPin()) {
        phone_number = new_phone_number;
        cout << "Phone number changed successfully.\n";
        return true;
    }
    cout <<"=================\n"
           "! Access denied !\n"
           "=================\n";
    return false;
}

//methods related to viewing data
void Account::view_profile() const {
    if (verifyPin()) {
        cout<<"--------------------------------------------\n";
        cout<<"Name : "<<first_name<<" "<<last_name<<endl;
        cout<<"ID : " << ID << endl;
        cout<<"Address : " << address << endl;
        cout<<"Phone number : " << phone_number << endl;
        cout<<"Account type : " << type_to_string() << endl;
        cout<<"--------------------------------------------\n";
        return;
    }
    cout <<"=================\n"
           "! Access denied !\n"
           "=================\n";
}
void Account::transaction_history() const {
    if (verifyPin()) {
        if (transactions.empty()) {
            cout << "There are no transactions yet. \n";
            return;
        }
        cout << "\nTransaction History :\n";
        for (const string tran: transactions) {
            cout << tran << endl;
        }
        cout << endl << endl;
        return;
    }
    cout <<"=================\n"
           "! Access denied !\n"
           "=================\n";
}

//Getters
string Account::get_first_name() const {
    return first_name;
}
string Account::get_last_name() const {
    return last_name;
}
string Account::get_PIN() const {
    return PIN;
}
string Account::get_address() const {
    return address;
}
string Account::get_phone_number() const {
    return phone_number;
}
double Account::get_balance() const {
    return balance;
}
#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;

enum Account_type {Standard, Savings, Business};

class Account {
protected:
    double balance;
    string first_name , last_name , ID;
    string PIN , address , phone_number;
    vector<string> transactions;
    Account_type account_type;

public:
public:
        Account(string fname, string lname, string id,
                string PIN, string address, string phone_number,
                Account_type accountType, double balance = 0);

        Account(const Account* copied, string PIN,
                Account_type newtype, double balance);

        //method to take PIN from user to access operation and compare it to user's true PIN
        bool verifyPin() const;
        //method to return account type as a string to print it when wanted
        string type_to_string()const;
        //methods related to money:
        virtual bool withdraw(double withdrawal);
        virtual bool deposit(double dep);
        bool check_balance() const;
        virtual bool transfer_to(Account &receiver , double amount);

        //methods related to changing information (PIN, address, number):
        bool change_address(const string &new_address);
        bool change_PIN();
        bool change_phone_number(const string &new_phone_number);

        //methods related to viewing data
        void view_profile() const;
        void transaction_history() const;

        virtual string get_first_name() const;
        virtual string get_last_name() const;
        virtual string get_PIN() const;
        virtual string get_address() const;
        virtual string get_phone_number() const;
        virtual double get_balance() const;
};

#include "BankStorage.h"

#include "StandardAccount.h"
#include "BusinessAccount.h"
#include "SavingsAccount.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static string after_colon(const string& text){
    int colon =text.find(":"); //finds the index of the colon
    return text.substr(colon +2); //returns the string after the colon note: substr uses numbers not index unlike .find
}
void save_file (const map<const string , User*> Users){
    ofstream file("BANK.txt");
    if (!file){
        cout<<"! Error creating a file !\n";
        return;
    }
    for (const auto& [id, user] : Users) {
        if (user->main_account!=NULL) {
            Account* acc=user->main_account;
            file <<"First name: " <<acc->get_first_name() << endl
                 <<"Last name: "<< acc->get_last_name() << endl
                 <<"ID: " << id << endl
                 <<"Account type: "<<acc->type_to_string() << endl
                 <<"PIN: "<< acc->get_PIN() <<endl
                 <<"Address: "<< acc->get_address() << endl
                 <<"Phone number: "<< acc->get_phone_number() << endl
                 <<"Balance: "<< acc->get_balance() << endl;
            file<<"\n=========================================\n\n";
        }
        if (user->savings_account!=NULL) {
            Account* acc=user->savings_account;
            file <<"First name: " <<acc->get_first_name() << endl
                 <<"Last name: "<< acc->get_last_name() << endl
                 <<"ID: " << id << endl
                 <<"Account type: "<<acc->type_to_string() << endl
                 <<"PIN: "<< acc->get_PIN() <<endl
                 <<"Address: "<< acc->get_address() << endl
                 <<"Phone number: "<< acc->get_phone_number() << endl
                 <<"Balance: "<< acc->get_balance() << endl;
            file<<"\n=========================================\n\n";
        }
    }
    file.close();
    return;
}
void read_file (map<const string , User*> &Users){
    ifstream file("BANK.txt");
    if(!file){
        cout<<"File doesn't eist.";
        return;
    }
    string temp;
    string id,firstname,lastname,phonenumber,address,accounttype,pin;
    double balance;
    while (getline(file,temp)){
        if(temp.empty())
            continue;
        firstname= after_colon(temp);
        getline(file,temp);
        lastname= after_colon(temp);
        getline(file,temp);
        id= after_colon(temp);
        getline(file,temp);
        accounttype= after_colon(temp);
        getline(file,temp);
        pin= after_colon(temp);
        getline(file,temp);
        address= after_colon(temp);
        getline(file,temp);
        phonenumber= after_colon(temp);
        getline(file,temp);
        bool invalid_balance = false;
        try {
            balance = stod(after_colon(temp));
        }
        catch (exception e) {
            cout << "Error reading balance for ID " << id;
            cout << "Skipping this account.\n";
            invalid_balance=true;
        }
        getline(file, temp);
        getline(file, temp);
        if (!Users.count(id))
            Users[id] = new User(id);
        if (accounttype == "Standard" && (balance > 1000000 || balance<0))
            invalid_balance = true;
        else if (accounttype == "Business" && (balance > 20000000 || balance<0))
            invalid_balance = true;
        else if (accounttype == "Savings" && (balance > 10000000 || balance<0))
            invalid_balance = true;
        if (invalid_balance) {
            cout << "Balance error for "<<accounttype<<" account of user ID "<<id<<". Skipping account.\n";
            continue;
        }
        Account* acc = NULL;
        if(accounttype=="Standard"){
            Account_type ac=Standard;
            acc= new Standard_Account(firstname,lastname,id,pin,address,phonenumber,ac,balance);
        }
        else if(accounttype=="Business"){
            Account_type ac=Business;
            acc= new Business_Account(firstname,lastname,id,pin,address,phonenumber,ac,balance);
        }
        else{
            Account_type ac=Savings;
            acc= new Savings_Account(firstname,lastname,id,pin,address,phonenumber,ac,balance);
        }
        Users[id]->add_account(acc);
    }
    file.close();
    cout<<"File upload complete.\n";
}
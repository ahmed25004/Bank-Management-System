#include <iostream>
#include <vector>
#include <map>
#include <fstream>


#include "Account.h"
#include "StandardAccount.h"
#include "BusinessAccount.h"
#include "SavingsAccount.h"
#include "User.h"
#include "BankStorage.h"
#include "Utils.h"

class Account;
using namespace std;

int main(){
    map<const string , User*> Users;
    read_file(Users);
    bool loop=true;
	while (loop){
		cout<<"====================\n"
              "Choose an operation:\n"
              "1) Create an account\n"
              "2) Sign in\n"
              "3) Exit\n"
              "====================\n\n"
              "Please choose an operation : ";
        char main_choice;
		cin>>main_choice;
		switch (main_choice){
			case '1':{
                system("cls");
				double balance=0;
				string fname,lname,id,PIN,CPIN,address,phone_number;
                Account_type accountType;
                cout<<"\n================================\n";
                cin.ignore();
                cout<<"Please enter your national ID: ";
                cin>>id;
                if(Users.count(id)){
                    User* user= Users[id];
                    if(user->main_account!=NULL && user->savings_account!=NULL){
                        cout<<"You cannot create more accouts as you already have a main and a savings account.\n";
                        break;
                    }
                    Account* old=NULL;
                    if(user->main_account==NULL){
                        old=user->savings_account;
                        cout<<"Welcome back "<<old->get_first_name()<<" "<<old->get_last_name()<<".\nDo you wish to create a main accout?\n";
                        char c;
                        cin>>c;
                        switch (c) {
                            case 'y':
                            case 'Y':{
                                cout<<"Wonderful, please provide missing data and we will create a new account with the same info as the old one.\n";
                                cout << "Choose account type:\n1) Standard\n2) Business\n";
                                int type_choice;
                                cin >> type_choice;
                                switch (type_choice) {
                                    case 2: accountType = Business; break;
                                    default: accountType = Standard; break;
                                }
                                PIN=PINcreation();
                                cout<<"Your current balance is 0, do you wish to add to your balance? (y/n) : ";
                                char balance_choice;
                                cin>>balance_choice;
                                if (balance_choice == 'y' || balance_choice == 'Y') {
                                    cout << "Enter the amount of money: ";
                                    cin >> balance;
                                    cout << balance << " was added to your account.\n";
                                }
                                if (accountType==Business)
                                    user->main_account= new Business_Account(old,PIN,accountType,balance);
                                else
                                    user->main_account= new Standard_Account(old,PIN,accountType,balance);
                                cout<<"=============================================\n";
                                cout<<"Congratulations account created successfully!\n";
                                cout<<"=============================================\n";
                                break;
                            }
                            case 'N':
                            case 'n':
                            default:
                                break;
                        }
                    }
                    if(user->savings_account==NULL){
                        old=user->main_account;
                        cout<<"Welcome back "<<old->get_first_name()<<" "<<old->get_last_name()<<".\nDo you wish to create a savings accout?\n";
                        char c;
                        cin>>c;
                        switch (c) {
                            case 'y':
                            case 'Y':{
                                cout<<"Wonderful, please provide missing data and we will create a new account with the same info as the old one.\n";
                                accountType = Savings;
                                PIN=PINcreation();
                                cout<<"Your current balance is 0, do you wish to add to your balance? (y/n) : ";
                                char balance_choice;
                                cin>>balance_choice;
                                if (balance_choice == 'y' || balance_choice == 'Y') {
                                    cout << "Enter the amount of money: ";
                                    cin >> balance;
                                    cout << balance << " was added to your account.\n";
                                }
                                user->savings_account= new Savings_Account(old,PIN,accountType,balance);
                                cout<<"=============================================\n";
                                cout<<"Congratulations account created successfully!\n";
                                cout<<"=============================================\n";
                                break;
                            }
                            case 'N':
                            case 'n':
                            default:
                                break;
                        }
                    }
                    break;
                }
                cin.ignore();
                cout<<"Please enter your first name: ";
                getline(cin, fname);
				cout<<"Please enter your last name: ";
                getline(cin, lname);
				cout<<"Please enter your address: ";
                cin.ignore();
                getline(cin, address);
                cout<<"Please enter your phone number: ";
                cin>>phone_number;
                cout << "Choose account type:\n1) Standard\n2) Savings\n3) Business\n";
                int type_choice;
                cin >> type_choice;
                switch (type_choice) {
                    case 2: accountType = Savings; break;
                    case 3: accountType = Business; break;
                    default: accountType = Standard; break;
                }
				PIN=PINcreation(); // A function containing the process of creating a PIN
				cout<<"Your current balance is 0, do you wish to add to your balance? (y/n) : ";
				char balance_choice;
				cin>>balance_choice;
                if (balance_choice == 'y' || balance_choice == 'Y') {
                    do{
                        if(balance>20000)
                            cout<<"Please only depost a maximum ammount of 10,000 when creating a new account.\nRe-";
                        cout << "Enter the amount of money: ";
                        cin >> balance;
                        cout << balance << " was added to your account.\n";
                    } while (balance>20000);
                }
                Account* accnew=NULL;
                User* user= new User(id);
                if(accountType==Standard)
                    accnew= new Standard_Account(fname,lname,id,PIN,address,phone_number,accountType,balance);
                else if(accountType==Business)
                    accnew= new Business_Account(fname,lname,id,PIN,address,phone_number,accountType,balance);
                else
                    accnew= new Savings_Account(fname,lname,id,PIN,address,phone_number,accountType,balance);
                user->add_account(accnew);
                Users[id]=user;
                cout<<"=============================================\n";
                cout<<"Congratulations account created successfully!\n";
                cout<<"=============================================\n";
                break;
			}
			case '2':{
				string id;
                system("cls");
                cout<<"Sign in using your National ID : ";
                cin>>id;
                if(!Users.count(id)){
                    cout<<"==================\n"
                          "! User not found !\n"
                          "==================\n";
                    break;
                }
                User* user=Users[id];
                cout<<"Accounts found : \n";
                int i=1;
                if(user->main_account!=NULL)
                    cout<<i++<<") Main account\n";
                if(user->savings_account!=NULL)
                    cout<<i++<<") Savings account\n";
                int choice;
                cout<<"Choose an account : ";
                cin>>choice;
                Account* account=NULL;
                if (choice==1 && user->main_account!=NULL)
                    account=user->main_account;
                else if(choice==2 && user->savings_account!=NULL)
                    account=user->savings_account;
                else{
                    cout << "Invalid choice.\n";
                    break;
                }
                if(account->verifyPin()){
                    system("cls");
                    cout<<"===========\n"
                          "- WELCOME -\n"
                          "===========\n";
                } else{
                    cout<<"Wrong PIN.\n";
                    break;
                }
                bool log_in_log_out= true;
                while (log_in_log_out){
                    cout<<"===============================\n"
                          "Choose an operation:\n"
                          "1) Withdraw\n"
                          "2) Deposit\n"
                          "3) Check balance\n"
                          "4) View profile data\n"
                          "5) Transaction history\n"
                          "6) Transfer money\n"
                          "7) Upgrade account to Business\n"
                          "8) Change personal info\n"
                          "9) Log out\n"
                          "===============================\n\n"
                          "Please choose an operation : ";
                    int op_choice;
                    cin>>op_choice;
                    switch (op_choice) {
                        case 1:{
                            double amount;
                            cout<<"Enter amount to withdraw : ";
                            cin>>amount;
                            account->withdraw(amount);
                            break;
                        }
                        case 2:{
                            double amount;
                            cout<<"Enter amount to deposit : ";
                            cin>>amount;
                            account->deposit(amount);
                            break;
                        }
                        case 3:{
                            account->check_balance();
                            break;
                        }
                        case 4:{
                            account->view_profile();
                            break;
                        }
                        case 5:{
                            account->transaction_history();
                            break;
                        }
                        case 6:{
                            if(account->type_to_string()=="Savings"){
                                cout << "Transfers are not allowed from a Saving Account.\n";
                                break;
                            }
                            string recipient;
                            cout<<"Please provide the recipient id: ";
                            cin>>recipient;
                            if(!Users.count(recipient)){
                                cout<<"Recipient not found.\n";
                                break;
                            }
                            User * rec =Users[recipient];
                            Account* Recipient=NULL;
                            if(rec->main_account!=NULL)
                                Recipient=rec->main_account;
                            if(Recipient==NULL){
                                cout<<"Recipient has no main account.\n";
                                break;
                            }

                            double amount;
                            cout << "Enter amount to transfer: ";
                            cin >> amount;
                            account->transfer_to(*Recipient, amount);
                            break;
                        }
                        case 7:{

                            if(user->main_account->type_to_string()=="Business"){
                                cout<<"Your account is already a business account.\n";
                                break;
                            }
                            if(account->type_to_string()=="Savings"){
                                cout<<"Cannot upgrade a savings account.\n";
                                break;
                            }
                            double balance=0;
                            string fname,lname,PIN,address,phone_number;
                            Account_type accountType=Business;
                            fname=user->main_account->get_first_name();
                            lname=user->main_account->get_last_name();
                            PIN=user->main_account->get_PIN();
                            address=user->main_account->get_address();
                            phone_number=user->main_account->get_phone_number();
                            balance=user->main_account->get_balance();
                            delete user->main_account;
                            user->main_account= new Business_Account(fname,lname,id,PIN,address,phone_number,accountType,balance);
                            cout << "Account successfully upgraded to Business.\n";
                            break;
                        }
                        case 8:{
                            cout<<"=========================\n"
                                  "1) Change address\n"
                                  "2) Change phone number\n"
                                  "3) Change PIN\n"
                                  "=========================\n"
                                  "Choose what do you want to change: ";
                            int changer;
                            cin>>changer;
                            switch (changer) {
                                case 1:{
                                    string changedadd;
                                    cout<<"Enter the new address you want : ";
                                    getline(cin, changedadd);
                                    account->change_address(changedadd);
                                    break;
                                }
                                case 2:{
                                    string changephone;
                                    cout<<"Enter the new phone number you want : ";
                                    cin>>changephone;
                                    account->change_phone_number(changephone);
                                    break;
                                }
                                case 3:{
                                    account->change_PIN();
                                    break;
                                }
                                default:
                                    cout<<"Invalid choice";
                            }


                        }
                        case 9:{
                            log_in_log_out= false;
                            system("cls");
                            break;
                        }

                        default:
                            cout<<"Invalide choice. \n";
                    }
                }
				break;
			}
            case '3':{
                save_file(Users);
                for (auto& [id, user] : Users) {
                    delete user->main_account;
                    delete user->savings_account;
                    delete user;
                }
                Users.clear();
                loop= false;
                break;
            }
            default: {
                cout << "wrong input.\n";
            }
		}
	}
}
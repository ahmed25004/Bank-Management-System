#include "Utils.h"

#include <iostream>
#include <cctype>

using namespace std;

//method to create PIN and confirm it and check if its all numbers and not exceeding 4 numbers
string PINcreation (){
    string newPIN,confirmation;
    bool all_digits=true;
    do{
        do{
            all_digits=true;
            cout<<"Create a 4-digit PIN: ";
            cin>>newPIN;
            for(int i=0; i<4; i++)
                if(!isdigit(newPIN[i]))
                    all_digits= false;
            if (newPIN.size()!=4 || !all_digits)
                cout<<"-------------------------------\n"
                      "!!!  Please enter 4 digits  !!!\n"
                      "-------------------------------\n";
        }while(newPIN.size()!=4 || !all_digits);
        cout<<"Please confirm your PIN: ";
        cin>>confirmation;
        if( newPIN != confirmation )
            cout<<"-------------------------------------------------------\n"
                  "!!!  PIN is not the same, Please re-enter your PIN  !!!\n"
                  "-------------------------------------------------------\n";
    }while( newPIN != confirmation );
    return newPIN;
}
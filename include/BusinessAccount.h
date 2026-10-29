#pragma once

#include "StandardAccount.h"

class Business_Account : public Standard_Account {
protected:
    double deposit_limit = 30000;
    double withdrawal_limit = 30000;
    double transfer_limit = 200000;
    double balance_limit = 20000000;

public:
    Business_Account(const string& first_name,
                     const string& last_name,
                     const string& id,
                     const string& pin,
                     const string& address,
                     const string& phone,
                     Account_type type,
                     double balance);

    Business_Account(const Account* copied,
                     string PIN,
                     Account_type newtype,
                     double balance);
};
#pragma once

#include "Account.h"

class Standard_Account : public Account {
private:
    double deposit_limit = 10000;
    double withdrawal_limit = 10000;
    double transfer_limit = 20000;
    double balance_limit = 1000000;

public:
    Standard_Account(const string& first_name,
                     const string& last_name,
                     const string& id,
                     const string& pin,
                     const string& address,
                     const string& phone,
                     Account_type type,
                     double balance);

    Standard_Account(const Account* copied,
                     string PIN,
                     Account_type newtype,
                     double balance);

    bool withdraw(double withdrawal) override;
    bool deposit(double deposit) override;

    bool transfer_to(Standard_Account& receiver, double amount);
};
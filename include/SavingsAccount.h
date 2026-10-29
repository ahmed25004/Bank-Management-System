#pragma once

#include "Account.h"
class Standard_Account;
class Savings_Account : public Account {
private:
    double interest_rate = 0.06;
    double balance_limit = 10000000;

public:
    Savings_Account(const string& first_name,
                    const string& last_name,
                    const string& id,
                    const string& pin,
                    const string& address,
                    const string& phone,
                    Account_type type,
                    double balance);

    Savings_Account(const Account* copied,
                    string PIN,
                    Account_type newtype,
                    double balance);

    bool transfer_to(Standard_Account& receiver, double amount);
    bool apply_interest();

    bool withdraw(double withdrawal) override;
    bool deposit(double deposit) override;
};
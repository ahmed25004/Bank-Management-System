#include "BusinessAccount.h"

Business_Account::Business_Account(
    const string& first_name,
    const string& last_name,
    const string& id,
    const string& pin,
    const string& address,
    const string& phone,
    Account_type type,
    double balance)
    : Standard_Account(first_name, last_name, id, pin,
                       address, phone, type, balance) {}

Business_Account::Business_Account(
    const Account* copied,
    string PIN,
    Account_type newtype,
    double balance)
    : Standard_Account(copied, PIN, newtype, balance) {}
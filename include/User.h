#pragma once

#include "Account.h"

class User {
public:
    string national_id;

    Account* main_account = nullptr;
    Account* savings_account = nullptr;

    User(const string& id);

    void add_account(Account* account);
};
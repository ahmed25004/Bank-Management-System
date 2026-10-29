#include "User.h"

User::User(const string& id)
    : national_id(id) {}

void User::add_account(Account* account) {
    if (account->type_to_string() == "Standard" ||
        account->type_to_string() == "Business") {

        main_account = account;
        }

    if (account->type_to_string() == "Savings") {
        savings_account = account;
    }
}
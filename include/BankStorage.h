#pragma once

#include <map>
#include <string>
#include "User.h"

using std::map;
using std::string;

void save_file(const map<const string, User*> Users);

void read_file(map<const string, User*>& Users);
cmake_minimum_required(VERSION 3.20)

project(Bank_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bank_Management_System
        src/main.cpp
        include/Account.h
        src/Account.cpp
        include/StandardAccount.h
        src/StandardAccount.cpp
        src/BusinessAccount.cpp
        include/BusinessAccount.h
        include/SavingsAccount.h
        src/SavingsAccount.cpp
        include/User.h
        src/User.cpp
        include/BankStorage.h
        src/BankStorage.cpp
        include/Utils.h
        src/Utils.cpp
)

target_include_directories(Bank_Management_System PRIVATE include)
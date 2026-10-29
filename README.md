# Bank Management System

A console-based banking management system developed in **C++17**, demonstrating Object-Oriented Programming (OOP), inheritance, polymorphism, and file handling.

Originally developed as a final project for the **Basics of Programming 2** course at Budapest University of Technology and Economics (BME).

## Features

- Create and manage Standard, Business, and Savings accounts.
- Support up to two accounts per customer.
- Secure account access using a four-digit PIN.
- Deposit and withdraw money.
- Transfer funds between eligible accounts.
- View account balances and transaction history.
- Update personal information and PIN.
- Upgrade Standard accounts to Business accounts.
- Apply 6% interest to Savings accounts.
- Save and load account information using text files.

## Technologies

- C++17
- CMake
- Object-Oriented Programming
- C++ Standard Library (`map`, `vector`, `fstream`)
- CLion

## Project Structure

```text
Bank-Management-System/
├── include/              # Header files
├── src/                  # C++ implementations
├── docs/                 # Project documentation
├── CMakeLists.txt         # Build configuration
├── .gitignore
└── README.md
```

## Build and Run

### Requirements

- C++17-compatible compiler
- CMake 3.20 or newer

### Using CLion

1. Clone or download the repository.
2. Open the project folder in CLion.
3. Allow CMake to configure the project.
4. Build and run the `Bank_Management_System` target.

### Using the terminal

```bash
cmake -S . -B build
cmake --build build
```

Run the generated executable from the build directory.

## Data Storage

Account information is stored locally in `BANK.txt`.

This file is excluded from Git version control because it contains account data, including PINs.

**Note:** This project is an educational banking simulation and is not intended for real financial transactions or storing sensitive personal information.

## Documentation

The original project analysis and documentation are available in [`docs/documentation.pdf`](docs/documentation.pdf).

## Future Improvements

- Improve account authentication and security.
- Fix account-specific transaction limit enforcement.
- Replace raw pointers with smart pointers.
- Introduce database storage.
- Add automated unit tests.
- Improve input validation and error handling.
- Add transaction timestamps and automatic savings interest.

## Author

Ahmed El Sheikh

Developed as an academic C++ programming project.
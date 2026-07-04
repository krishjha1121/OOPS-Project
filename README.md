# Bank & ATM Management System

A comprehensive command-line banking application built using modern C++ and Object-Oriented Programming (OOP) principles. 

This project is modularized into distinct components to demonstrate robust software engineering practices, separating Bank Management functionalities and ATM functionalities into separate classes and file structures.

## Features
- **Account Management**: Create, view, edit, and delete user accounts.
- **Transactions**: Secure deposits, withdrawals, and inter-account transfers.
- **Payments System**: Track and record customized payments.
- **ATM Module**: Independent user login for specific account access via an ATM simulation interface.
- **Object-Oriented Design**: Utilizes classes, encapsulation, data abstraction, and a professional multi-file architecture (`.h` and `.cpp`).

## Project Structure
- `include/`: Header files defining the core classes.
- `src/`: Source files implementing the logic.
- `CMakeLists.txt`: Build configuration file.

## Build and Run

You can build the project using CMake:

```bash
mkdir build
cd build
cmake ..
make
./BankSystem
```

Alternatively, you can compile it manually using `g++`:
```bash
g++ -std=c++14 src/*.cpp -I include -o BankSystem
./BankSystem
```

## Technologies Used
- C++ (C++14 minimum)
- Object-Oriented Programming (OOP)
- CMake Build System
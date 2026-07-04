cmake_minimum_required(VERSION 3.10)
project(BankAndATMSystem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory
include_directories(include)

# Source files
set(SOURCES
    src/Account.cpp
    src/BankManagementSystem.cpp
    src/ATMSystem.cpp
    src/main.cpp
)

# Executable
add_executable(BankSystem ${SOURCES})

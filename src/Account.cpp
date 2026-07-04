#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(int accNumber, const string &accName, double initialBalance)
    : accountNumber(accNumber), name(accName), balance(initialBalance) {}

int Account::getAccountNumber() const { 
    return accountNumber; 
}

string Account::getName() const { 
    return name; 
}

double Account::getBalance() const { 
    return balance; 
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}

void Account::display() const {
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Name: " << name << "\n";
    cout << "Balance: " << balance << "\n";
}

void Account::setName(const string &newName) {
    name = newName;
}

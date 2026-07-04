#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string name;
    double balance;
public:
    Account(int accNumber, const std::string &accName, double initialBalance);

    int getAccountNumber() const;
    std::string getName() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
    void setName(const std::string &newName);
};

#endif // ACCOUNT_H

#include "BankManagementSystem.h"
#include <iostream>
#include <limits>

using namespace std;

BankManagementSystem::BankManagementSystem() : nextAccountNumber(1001) {}

Account* BankManagementSystem::findAccount(int accNumber) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNumber)
            return &acc;
    }
    return nullptr;
}

void BankManagementSystem::addNewUser() {
    string name;
    double initialDeposit;
    cout << "Enter user name: ";
    getline(cin, name);
    cout << "Enter initial deposit amount: ";
    cin >> initialDeposit;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account newAccount(nextAccountNumber++, name, initialDeposit);
    accounts.push_back(newAccount);

    cout << "Account created successfully! Your account number is: "
         << newAccount.getAccountNumber() << "\n";
}

void BankManagementSystem::deposit() {
    int accNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* acc = findAccount(accNumber);
    if (!acc) {
        cout << "Account not found!\n";
        return;
    }
    cout << "Enter deposit amount: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    acc->deposit(amount);
    cout << "Deposit successful. New Balance: " << acc->getBalance() << "\n";
}

void BankManagementSystem::withdraw() {
    int accNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* acc = findAccount(accNumber);
    if (!acc) {
        cout << "Account not found!\n";
        return;
    }
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (acc->withdraw(amount)) {
        cout << "Withdrawal successful. New Balance: " << acc->getBalance() << "\n";
    } else {
        cout << "Insufficient balance!\n";
    }
}

void BankManagementSystem::transfer() {
    int sourceAcc, targetAcc;
    double amount;
    cout << "Enter source account number: ";
    cin >> sourceAcc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* src = findAccount(sourceAcc);
    if (!src) {
        cout << "Source account not found!\n";
        return;
    }

    cout << "Enter target account number: ";
    cin >> targetAcc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* tgt = findAccount(targetAcc);
    if (!tgt) {
        cout << "Target account not found!\n";
        return;
    }

    cout << "Enter transfer amount: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (src->withdraw(amount)) {
        tgt->deposit(amount);
        cout << "Transfer successful.\n";
    } else {
        cout << "Insufficient balance in source account!\n";
    }
}

void BankManagementSystem::payment() {
    int accNumber;
    double amount;
    string description;
    cout << "Enter account number: ";
    cin >> accNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* acc = findAccount(accNumber);
    if (!acc) {
        cout << "Account not found!\n";
        return;
    }
    cout << "Enter payment amount: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter payment description: ";
    getline(cin, description);

    if (acc->withdraw(amount)) {
        PaymentRecord pr { accNumber, amount, description };
        paymentRecords.push_back(pr);
        cout << "Payment successful. New Balance: " << acc->getBalance() << "\n";
    } else {
        cout << "Insufficient balance for payment!\n";
    }
}

void BankManagementSystem::searchUserRecord() {
    int accNumber;
    cout << "Enter account number to search: ";
    cin >> accNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* acc = findAccount(accNumber);
    if (!acc) {
        cout << "Account not found!\n";
    } else {
        acc->display();
    }
}

void BankManagementSystem::editUserRecord() {
    int accNumber;
    cout << "Enter account number to edit: ";
    cin >> accNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* acc = findAccount(accNumber);
    if (!acc) {
        cout << "Account not found!\n";
    } else {
        string newName;
        cout << "Enter new name: ";
        getline(cin, newName);
        acc->setName(newName);
        cout << "Account updated successfully.\n";
    }
}

void BankManagementSystem::deleteUserRecord() {
    int accNumber;
    cout << "Enter account number to delete: ";
    cin >> accNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getAccountNumber() == accNumber) {
            accounts.erase(it);
            cout << "Account deleted successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Account not found!\n";
    }
}

void BankManagementSystem::showAllRecords() {
    if (accounts.empty()) {
        cout << "No accounts available.\n";
        return;
    }
    for (auto &acc : accounts) {
        acc.display();
        cout << "-------------------------\n";
    }
}

void BankManagementSystem::showPaymentRecords() {
    if (paymentRecords.empty()) {
        cout << "No payment records available.\n";
        return;
    }
    for (auto &pr : paymentRecords) {
        cout << "Account Number: " << pr.accountNumber << "\n";
        cout << "Payment Amount: " << pr.amount << "\n";
        cout << "Description: " << pr.description << "\n";
        cout << "-------------------------\n";
    }
}

#include "ATMSystem.h"
#include <iostream>
#include <limits>

using namespace std;

ATMSystem::ATMSystem(BankManagementSystem* b) : bank(b), currentAccountNumber(-1) {}

void ATMSystem::userLogin() {
    int accNumber;
    cout << "Enter your account number: ";
    cin >> accNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* acc = bank->findAccount(accNumber);
    if (acc) {
        currentAccountNumber = accNumber;
        cout << "Login successful! Welcome, " << acc->getName() << "\n";
    } else {
        cout << "Account not found! Please try again.\n";
    }
}

void ATMSystem::checkBalance() {
    if (currentAccountNumber == -1) {
        cout << "Please login first.\n";
        return;
    }
    Account* acc = bank->findAccount(currentAccountNumber);
    if (acc) {
        cout << "Your current balance is: " << acc->getBalance() << "\n";
    }
}

void ATMSystem::withdrawAmount() {
    if (currentAccountNumber == -1) {
        cout << "Please login first.\n";
        return;
    }
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* acc = bank->findAccount(currentAccountNumber);
    if (acc) {
        if (acc->withdraw(amount)) {
            cout << "Withdrawal successful. New balance: " << acc->getBalance() << "\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }
}

void ATMSystem::accountDetails() {
    if (currentAccountNumber == -1) {
        cout << "Please login first.\n";
        return;
    }
    Account* acc = bank->findAccount(currentAccountNumber);
    if (acc) {
        acc->display();
    }
}

void ATMSystem::atmMenu() {
    int choice;
    do {
        cout << "\n--- ATM System Menu ---\n";
        cout << "1. User Login\n";
        cout << "2. Check Balance\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. Account Details\n";
        cout << "5. Logout\n";
        cout << "6. Go Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: userLogin(); break;
            case 2: checkBalance(); break;
            case 3: withdrawAmount(); break;
            case 4: accountDetails(); break;
            case 5:
                currentAccountNumber = -1;
                cout << "Logged out successfully.\n";
                break;
            case 6:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

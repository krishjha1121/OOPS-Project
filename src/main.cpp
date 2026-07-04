#include "BankManagementSystem.h"
#include "ATMSystem.h"
#include <iostream>
#include <limits>

using namespace std;

void bankManagementMenu(BankManagementSystem &bank) {
    int choice;
    do {
        cout << "\n--- Bank Management System Menu ---\n";
        cout << "1. New User (Create Account)\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Payment\n";
        cout << "6. Search User Record\n";
        cout << "7. Edit User Record\n";
        cout << "8. Delete User Record\n";
        cout << "9. Show All Records\n";
        cout << "10. Show Payment Records\n";
        cout << "11. Go Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:  bank.addNewUser(); break;
            case 2:  bank.deposit(); break;
            case 3:  bank.withdraw(); break;
            case 4:  bank.transfer(); break;
            case 5:  bank.payment(); break;
            case 6:  bank.searchUserRecord(); break;
            case 7:  bank.editUserRecord(); break;
            case 8:  bank.deleteUserRecord(); break;
            case 9:  bank.showAllRecords(); break;
            case 10: bank.showPaymentRecords(); break;
            case 11:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);
}

int main() {
    BankManagementSystem bank;
    ATMSystem atm(&bank);

    int choice;
    do {
        cout << "\n=== Main Menu ===\n";
        cout << "1. ATM System\n";
        cout << "2. Bank Management System\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                atm.atmMenu();
                break;
            case 2:
                bankManagementMenu(bank);
                break;
            case 3:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

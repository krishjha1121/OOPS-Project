#ifndef ATM_SYSTEM_H
#define ATM_SYSTEM_H

#include "BankManagementSystem.h"

class ATMSystem {
private:
    BankManagementSystem* bank; // pointer to BankManagementSystem
    int currentAccountNumber;   // -1 if not logged in

public:
    ATMSystem(BankManagementSystem* b);

    void userLogin();
    void checkBalance();
    void withdrawAmount();
    void accountDetails();
    void atmMenu();
};

#endif // ATM_SYSTEM_H

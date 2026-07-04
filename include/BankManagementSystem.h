#ifndef BANK_MANAGEMENT_SYSTEM_H
#define BANK_MANAGEMENT_SYSTEM_H

#include "Account.h"
#include "PaymentRecord.h"
#include <vector>

class BankManagementSystem {
private:
    std::vector<Account> accounts;
    std::vector<PaymentRecord> paymentRecords;
    int nextAccountNumber;

public:
    BankManagementSystem();

    Account* findAccount(int accNumber);
    void addNewUser();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void searchUserRecord();
    void editUserRecord();
    void deleteUserRecord();
    void showAllRecords();
    void showPaymentRecords();
};

#endif // BANK_MANAGEMENT_SYSTEM_H

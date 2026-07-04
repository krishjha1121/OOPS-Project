#ifndef PAYMENT_RECORD_H
#define PAYMENT_RECORD_H

#include <string>

struct PaymentRecord {
    int accountNumber;
    double amount;
    std::string description;
};

#endif // PAYMENT_RECORD_H

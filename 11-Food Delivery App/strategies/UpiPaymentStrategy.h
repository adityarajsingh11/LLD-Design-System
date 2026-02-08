#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// UpiPaymentStrategy PaymentStrategy ka concrete implementation hai
// Ye UPI ke through payment handle karta hai
class UpiPaymentStrategy : public PaymentStrategy {

private:
    string mobile;   // UPI se linked mobile number

public:
    // Constructor – mobile number initialize karta hai
    UpiPaymentStrategy(const string& mob) {
        mobile = mob;
    }

    // Strategy interface ka method implement karta hai
    // UPI payment simulate karta hai
    void pay(double amount) override {
        cout << "Paid Rs." << amount
             << " using UPI (" << mobile << ")" << endl;
    }
};

#endif // UPI_PAYMENT_STRATEGY_H

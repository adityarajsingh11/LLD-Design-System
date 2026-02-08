#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// CreditCardPaymentStrategy PaymentStrategy ka concrete implementation hai
// Ye credit card ke through payment handle karta hai
class CreditCardPaymentStrategy : public PaymentStrategy {

private:
    string cardNumber;   // user ka credit card number

public:
    // Constructor – card number initialize karta hai
    CreditCardPaymentStrategy(const string& card) {
        cardNumber = card;
    }

    // Strategy interface ka method implement kar raha hai
    // Credit card payment simulate karta hai
    void pay(double amount) override {
        cout << "Paid Rs." << amount
             << " using Credit Card (" << cardNumber << ")" << endl;
    }
};

#endif // CREDIT_CARD_PAYMENT_STRATEGY_H

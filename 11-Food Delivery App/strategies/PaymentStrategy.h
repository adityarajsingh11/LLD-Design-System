#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include <iostream>
#include <string>

using namespace std;

// PaymentStrategy ek interface (abstract class) hai
// Ye payment ka common contract define karta hai
class PaymentStrategy {

public:
    // Payment process karne ka method
    // Har concrete strategy isko implement karegi
    virtual void pay(double amount) = 0;

    // Virtual destructor for proper cleanup
    virtual ~PaymentStrategy() {}
};

#endif // PAYMENT_STRATEGY_H

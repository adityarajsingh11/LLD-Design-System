#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"

using namespace std;

// DeliveryOrder class Order ka child class hai
// Ye delivery type ke orders represent karti hai
class DeliveryOrder : public Order {

private:
    string userAddress;   // delivery ke liye user ka address

public:
    // Constructor
    DeliveryOrder() {
        userAddress = "";
    }

    // Order ka type batata hai (Runtime Polymorphism)
    string getType() const override {
        return "Delivery";
    }

    // -------- Getters and Setters --------

    // User ka delivery address set karta hai
    void setUserAddress(const string& addr) {
        userAddress = addr;
    }

    // User ka delivery address return karta hai
    string getUserAddress() const {
        return userAddress;
    }
};

#endif // DELIVERY_ORDER_H

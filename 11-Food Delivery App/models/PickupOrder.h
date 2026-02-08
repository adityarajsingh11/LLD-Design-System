#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "Order.h"

using namespace std;

// PickupOrder class Order ka child class hai
// Ye pickup type ke orders represent karti hai
class PickupOrder : public Order {

private:
    string restaurantAddress;   // pickup ke liye restaurant ka address

public:
    // Constructor
    PickupOrder() {
        restaurantAddress = "";
    }

    // Order ka type batata hai (Runtime Polymorphism)
    string getType() const override {
        return "Pickup";
    }

    // -------- Getters and Setters --------

    // Restaurant ka pickup address set karta hai
    void setRestaurantAddress(const string& addr) {
        restaurantAddress = addr;
    }

    // Restaurant ka pickup address return karta hai
    string getRestaurantAddress() const {
        return restaurantAddress;
    }
};

#endif // PICKUP_ORDER_H

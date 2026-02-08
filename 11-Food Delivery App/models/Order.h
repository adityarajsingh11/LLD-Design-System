#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../utils/TimeUtils.h"

using namespace std;

// Order ek abstract base class hai
// DeliveryOrder aur PickupOrder isse inherit karte hain
class Order {

protected:
    static int nextOrderId;      // auto-increment order id
    int orderId;                // unique order id
    User* user;                 // order place karne wala user
    Restaurant* restaurant;     // restaurant jahan se order hua
    vector<MenuItem> items;     // ordered items
    PaymentStrategy* paymentStrategy; // payment ka tarika (Strategy Pattern)
    double total;               // total bill amount
    string scheduled;           // order ka time (now / future)

public:
    // Constructor
    Order() {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = ++nextOrderId; // har order ko unique id milti hai
    }

    // Virtual destructor (polymorphic delete ke liye)
    virtual ~Order() {
        delete paymentStrategy;
    }

    // Payment process karta hai using selected strategy
    bool processPayment() {
        if (paymentStrategy) {
            paymentStrategy->pay(total);
            return true;
        } else {
            cout << "Please choose a payment mode first" << endl;
            return false;
        }
    }

    // Order ka type batata hai (Delivery / Pickup)
    // Child classes isko override karti hain
    virtual string getType() const = 0;

    // -------- Getters and Setters --------

    int getOrderId() const {
        return orderId;
    }

    void setUser(User* u) {
        user = u;
    }

    User* getUser() const {
        return user;
    }

    void setRestaurant(Restaurant* r) {
        restaurant = r;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    // Order ke items set karta hai aur total calculate karta hai
    void setItems(const vector<MenuItem>& its) {
        items = its;
        total = 0;
        for (auto &i : items) {
            total += i.getPrice();
        }
    }

    const vector<MenuItem>& getItems() const {
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* p) {
        paymentStrategy = p;
    }

    void setScheduled(const string& s) {
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }

    double getTotal() const {
        return total;
    }

    void setTotal(int total) {
        this->total = total;
    }
};

// Static member initialization
int Order::nextOrderId = 0;

#endif // ORDER_H

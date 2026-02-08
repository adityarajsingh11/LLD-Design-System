#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <vector>
#include <iostream>
#include "../models/Order.h"

using namespace std;

// OrderManager orders ko manage karne ke liye hai
// Ye class Singleton Pattern follow karti hai
class OrderManager {

private:
    vector<Order*> orders;          // sabhi placed orders ka list
    static OrderManager* instance;  // single global instance

    // Private constructor taaki object bahar se na ban sake
    OrderManager() {
        // Private Constructor
    }

public:
    // Singleton instance return karne ke liye static method
    static OrderManager* getInstance() {
        if (!instance) {
            instance = new OrderManager();
        }
        return instance;
    }

    // New order ko list me add karta hai
    void addOrder(Order* order) {
        orders.push_back(order);
    }

    // Sabhi orders ko print karta hai
    void listOrders() {
        cout << "\n--- All Orders ---" << endl;
        for (auto order : orders) {
            cout << order->getType()
                 << " order for " << order->getUser()->getName()
                 << " | Total: ₹" << order->getTotal()
                 << " | At: " << order->getScheduled()
                 << endl;
        }
    }
};

// Static member initialization
OrderManager* OrderManager::instance = nullptr;

#endif // ORDER_MANAGER_H

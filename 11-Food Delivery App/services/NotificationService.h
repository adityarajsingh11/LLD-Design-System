#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include <iostream>
#include "../models/Order.h"

using namespace std;

// NotificationService user ko order related notification dikhane ke liye hai
// Ye ek utility-style service hai (no object state)
class NotificationService {

public:
    // Static method – order place hone ke baad notification show karta hai
    static void notify(Order* order) {

        cout << "\nNotification: New " << order->getType()
             << " order placed!" << endl;

        cout << "---------------------------------------------" << endl;

        // Basic order details
        cout << "Order ID: " << order->getOrderId() << endl;
        cout << "Customer: " << order->getUser()->getName() << endl;
        cout << "Restaurant: " << order->getRestaurant()->getName() << endl;

        cout << "Items Ordered:\n";

        // Ordered items print kar rahe hain
        const vector<MenuItem>& items = order->getItems();
        for (const auto& item : items) {
            cout << "   - " << item.getName()
                 << " (Rs." << item.getPrice() << ")\n";
        }

        // Final order summary
        cout << "Total: Rs." << order->getTotal() << endl;
        cout << "Scheduled For: " << order->getScheduled() << endl;
        cout << "Payment: Done" << endl;

        cout << "---------------------------------------------" << endl;
    }
};

#endif // NOTIFICATION_SERVICE_H

#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "../models/Order.h"
#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../strategies/PaymentStrategy.h"
#include <vector>
#include <string>

using namespace std;

// OrderFactory ek abstract factory hai
// Jo order creation ka contract define karta hai
class OrderFactory {

public:
    // Ye factory method hai
    // Concrete factories (NowOrderFactory / ScheduledOrderFactory)
    // isko implement karti hain
    virtual Order* createOrder(
        User* user,                     // order place karne wala user
        Cart* cart,                     // user ka cart
        Restaurant* restaurant,         // selected restaurant
        const vector<MenuItem>& menuItems, // selected food items
        PaymentStrategy* paymentStrategy,  // payment method
        double totalCost,               // total bill
        const string& orderType         // Delivery / Pickup
    ) = 0;

    // Virtual destructor for proper cleanup
    virtual ~OrderFactory() {}
};

#endif // ORDER_FACTORY_H

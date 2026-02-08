#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"

using namespace std;

// NowOrderFactory ek concrete factory hai
// Jo "abhi ka order" (instant order) create karti hai
class NowOrderFactory : public OrderFactory {

public:
    // Factory method jo Order object create karta hai
    // Ye method runtime par decide karta hai ki
    // DeliveryOrder banana hai ya PickupOrder
    Order* createOrder(
        User* user,                 // jis user ne order place kiya
        Cart* cart,                 // user ka cart (items already selected)
        Restaurant* restaurant,     // selected restaurant
        const vector<MenuItem>& menuItems, // cart ke andar ke items
        PaymentStrategy* paymentStrategy,  // payment ka tarika (UPI, Card, etc.)
        double totalCost,           // total bill amount
        const string& orderType     // "Delivery" ya "Pickup"
    ) override {

        Order* order = nullptr; // base class pointer

        // Agar order type "Delivery" hai
        if (orderType == "Delivery") {

            // DeliveryOrder ka object create kar rahe hain
            auto deliveryOrder = new DeliveryOrder();

            // User ka address set kar rahe hain (kyunki delivery hai)
            deliveryOrder->setUserAddress(user->getAddress());

            // Order pointer ko deliveryOrder se point kara diya
            order = deliveryOrder;
        }
        else {
            // Agar pickup order hai

            // PickupOrder ka object create kar rahe hain
            auto pickupOrder = new PickupOrder();

            // Restaurant ka address set kar rahe hain (pickup location)
            pickupOrder->setRestaurantAddress(restaurant->getLocation());

            // Order pointer ko pickupOrder se point kara diya
            order = pickupOrder;
        }

        // Ab common properties set kar rahe hain
        // Ye dono order type (Delivery / Pickup) ke liye same hoti hain

        order->setUser(user);                         // order kisne place kiya
        order->setRestaurant(restaurant);             // kis restaurant se order hai
        order->setItems(menuItems);                   // kaunse items order kiye gaye
        order->setPaymentStrategy(paymentStrategy);   // payment ka strategy
        order->setScheduled(TimeUtils::getCurrentTime()); // current time set
        order->setTotal(totalCost);                   // total bill amount

        // Final Order object return kar diya
        return order;
    }
};

#endif // NOW_ORDER_FACTORY_H

#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"

using namespace std;

// ScheduledOrderFactory ek concrete factory hai
// Jo future time ke liye order create karti hai
class ScheduledOrderFactory : public OrderFactory {

private:
    string scheduleTime; // kis time par order schedule hoga

public:
    // Constructor me schedule time set kiya jata hai
    ScheduledOrderFactory(string scheduleTime) {
        this->scheduleTime = scheduleTime;
    }

    // Factory method jo scheduled order create karta hai
    Order* createOrder(
        User* user,                     // order place karne wala user
        Cart* cart,                     // user ka cart
        Restaurant* restaurant,         // selected restaurant
        const vector<MenuItem>& menuItems, // selected items
        PaymentStrategy* paymentStrategy,  // payment method
        double totalCost,               // total bill
        const string& orderType         // Delivery / Pickup
    ) override {

        Order* order = nullptr;

        // Agar delivery order hai
        if(orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();

            // Delivery ke liye user ka address set
            deliveryOrder->setUserAddress(user->getAddress());

            order = deliveryOrder;
        } 
        else {
            // Pickup order ke liye
            auto pickupOrder = new PickupOrder();

            // Pickup ke liye restaurant ka address set
            pickupOrder->setRestaurantAddress(restaurant->getLocation());

            order = pickupOrder; // base pointer ko assign
        }

        // Common properties set kar rahe hain
        order->setUser(user);                     // user details
        order->setRestaurant(restaurant);         // restaurant details
        order->setItems(menuItems);               // order items
        order->setPaymentStrategy(paymentStrategy); // payment strategy
        order->setScheduled(scheduleTime);        // scheduled future time
        order->setTotal(totalCost);               // total amount

        return order; // final scheduled order
    }
};

#endif // SCHEDULED_ORDER_FACTORY_H

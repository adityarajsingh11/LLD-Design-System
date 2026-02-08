#ifndef TOMATO_APP_H
#define TOMATO_APP_H

#include <vector>
#include <string>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"

using namespace std;

// TomatoApp Facade class hai
// Ye poore system ke complex flow ko simple interface me expose karti hai
class TomatoApp {

public:
    // Constructor – sample restaurants initialize karta hai
    TomatoApp() {
        initializeRestaurants();
    }

    // Initial dummy restaurants aur unka menu setup karta hai
    void initializeRestaurants() {
        Restaurant* restaurant1 = new Restaurant("Bikaner", "Delhi");
        restaurant1->addMenuItem(MenuItem("P1", "Chole Bhature", 120));
        restaurant1->addMenuItem(MenuItem("P2", "Samosa", 15));

        Restaurant* restaurant2 = new Restaurant("Haldiram", "Kolkata");
        restaurant2->addMenuItem(MenuItem("P1", "Raj Kachori", 80));
        restaurant2->addMenuItem(MenuItem("P2", "Pav Bhaji", 100));
        restaurant2->addMenuItem(MenuItem("P3", "Dhokla", 50));

        Restaurant* restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");
        restaurant3->addMenuItem(MenuItem("P1", "Masala Dosa", 90));
        restaurant3->addMenuItem(MenuItem("P2", "Idli Vada", 60));
        restaurant3->addMenuItem(MenuItem("P3", "Filter Coffee", 30));

        // Restaurants ko singleton manager me add kar rahe hain
        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(restaurant1);
        restaurantManager->addRestaurant(restaurant2);
        restaurantManager->addRestaurant(restaurant3);
    }

    // Location ke basis par restaurants search karta hai
    vector<Restaurant*> searchRestaurants(const string& location) {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

    // User ke cart ke liye restaurant select karta hai
    void selectRestaurant(User* user, Restaurant* restaurant) {
        Cart* cart = user->getCart();
        cart->setRestaurant(restaurant);
    }

    // Selected restaurant ke menu se item cart me add karta hai
    void addToCart(User* user, const string& itemCode) {
        Restaurant* restaurant = user->getCart()->getRestaurant();
        if (!restaurant) {
            cout << "Please select a restaurant first." << endl;
            return;
        }
        for (const auto& item : restaurant->getMenu()) {
            if (item.getCode() == itemCode) {
                user->getCart()->addItem(item);
                break;
            }
        }
    }

    // Immediate (Now) order checkout
    Order* checkoutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }

    // Scheduled order checkout (future time)
    Order* checkoutScheduled(User* user, const string& orderType,
                             PaymentStrategy* paymentStrategy,
                             const string& scheduleTime) {
        return checkout(user, orderType, paymentStrategy,
                        new ScheduledOrderFactory(scheduleTime));
    }

    // Common checkout logic (Factory Pattern use ho raha hai)
    Order* checkout(User* user, const string& orderType,
                    PaymentStrategy* paymentStrategy,
                    OrderFactory* orderFactory) {

        // Agar cart empty hai to checkout nahi hoga
        if (user->getCart()->isEmpty())
            return nullptr;

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        // Factory se order create kar rahe hain
        Order* order = orderFactory->createOrder(
            user, userCart, orderedRestaurant,
            itemsOrdered, paymentStrategy,
            totalCost, orderType
        );

        // Order ko singleton OrderManager me store kar rahe hain
        OrderManager::getInstance()->addOrder(order);
        return order;
    }

    // Payment process karta hai aur success par notification bhejta hai
    void payForOrder(User* user, Order* order) {
        bool isPaymentSuccess = order->processPayment();

        // Payment success hone par cart clear aur notification
        if (isPaymentSuccess) {
            NotificationService* notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }
    }

    // User ke cart ka summary print karta hai
    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getItems()) {
            cout << item.getCode() << " : "
                 << item.getName() << " : Rs."
                 << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : Rs."
             << user->getCart()->getTotalCost() << endl;
    }
};

#endif // TOMATO_APP_H

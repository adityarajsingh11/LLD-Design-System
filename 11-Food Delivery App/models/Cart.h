#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include <string>
#include "../models/MenuItem.h"
#include "../models/Restaurant.h"

using namespace std;

// Cart class user ke selected food items ko hold karti hai
// Ye ek time par sirf ek restaurant se order allow karti hai
class Cart {

private:
    Restaurant* restaurant;   // kis restaurant ka cart hai
    vector<MenuItem> items;   // selected menu items

public:
    // Constructor
    Cart() {
        restaurant = nullptr;
    }

    // Cart me item add karta hai
    void addItem(const MenuItem& item) {

        // Agar restaurant set nahi hai to item add nahi hoga
        if (!restaurant) {
            cerr << "Cart: Set a restaurant before adding items." << endl;
            return;
        }
        items.push_back(item);
    }

    // Cart ke sabhi items ka total price nikalta hai
    double getTotalCost() const {
        double sum = 0;
        for (const auto& it : items) {
            sum += it.getPrice();
        }
        return sum;
    }

    // Check karta hai cart empty hai ya nahi
    bool isEmpty() {
        return (!restaurant || items.empty());
    }

    // Cart ko clear karta hai (order place hone ke baad)
    void clear() {
        items.clear();
        restaurant = nullptr;
    }

    // -------- Getters and Setters --------

    // Restaurant set karta hai (order start karte time)
    void setRestaurant(Restaurant* r) {
        restaurant = r;
    }

    // Cart ka restaurant return karta hai
    Restaurant* getRestaurant() const {
        return restaurant;
    }

    // Cart ke items return karta hai
    const vector<MenuItem>& getItems() const {
        return items;
    }
};

#endif // CART_H

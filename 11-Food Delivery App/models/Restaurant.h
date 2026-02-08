#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>
#include "MenuItem.h"

using namespace std;

// Restaurant class ek restaurant ko represent karti hai
// Isme basic details aur menu items store hote hain
class Restaurant {

private:
    static int nextRestaurantId;   // auto-increment restaurant id
    int restaurantId;              // unique restaurant id
    string name;                   // restaurant ka naam
    string location;               // restaurant ki location
    vector<MenuItem> menu;         // restaurant ka menu

public:
    // Constructor – restaurant details set karta hai
    Restaurant(const string& name, const string& location) {
        this->name = name;
        this->location = location;
        this->restaurantId = ++nextRestaurantId;
    }

    // Destructor (debug / clarity ke liye)
    ~Restaurant() {
        cout << "Destroying Restaurant: " << name
             << ", and clearing its menu." << endl;
        menu.clear();
    }

    // -------- Getters and Setters --------

    // Restaurant ka naam return karta hai
    string getName() const {
        return name;
    }

    // Restaurant ka naam update karta hai
    void setName(const string &n) {
        name = n;
    }

    // Restaurant ki location return karta hai
    string getLocation() const {
        return location;
    }

    // Restaurant ki location update karta hai
    void setLocation(const string &loc) {
        location = loc;
    }

    // Menu me naya item add karta hai
    void addMenuItem(const MenuItem &item) {
        menu.push_back(item);
    }

    // Restaurant ka complete menu return karta hai
    const vector<MenuItem>& getMenu() const {
        return menu;
    }
};

// Static member initialization
int Restaurant::nextRestaurantId = 0;

#endif // RESTAURANT_H

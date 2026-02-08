#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <vector>
#include <string>
#include <algorithm>
#include "../models/Restaurant.h"

using namespace std;

// RestaurantManager sabhi restaurants ko manage karta hai
// Ye class Singleton Pattern follow karti hai
class RestaurantManager {

private:
    vector<Restaurant*> restaurants;     // system ke saare restaurants
    static RestaurantManager* instance;  // single global instance

    // Private constructor taaki object bahar se na ban sake
    RestaurantManager() {
        // private constructor
    }

public:
    // Singleton instance return karta hai
    static RestaurantManager* getInstance() {
        if (!instance) {
            instance = new RestaurantManager();
        }
        return instance;
    }

    // New restaurant ko system me add karta hai
    void addRestaurant(Restaurant* r) {
        restaurants.push_back(r);
    }

    // Location ke basis par restaurants search karta hai
    vector<Restaurant*> searchByLocation(string loc) {
        vector<Restaurant*> result;

        // Input location ko lowercase me convert kar rahe hain
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);

        for (auto r : restaurants) {
            string rl = r->getLocation();

            // Restaurant location ko bhi lowercase me convert karte hain
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);

            // Agar location match hoti hai to result me add
            if (rl == loc) {
                result.push_back(r);
            }
        }
        return result;
    }
};

// Static member initialization
RestaurantManager* RestaurantManager::instance = nullptr;

#endif // RESTAURANT_MANAGER_H

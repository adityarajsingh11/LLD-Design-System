#include <iostream>
#include "TomatoApp.h"

using namespace std;

int main() {

    // TomatoApp ka object create kar rahe hain
    // Ye poore system ka Facade hai
    TomatoApp* tomato = new TomatoApp();

    // Ek user system me aata hai (Happy Flow start)
    User* user = new User(101, "Aditya", "Delhi");
    cout << "User: " << user->getName() << " is active." << endl;

    // User location ke basis par restaurants search karta hai
    vector<Restaurant*> restaurantList = tomato->searchRestaurants("Delhi");

    // Agar koi restaurant nahi mila
    if (restaurantList.empty()) {
        cout << "No restaurants found!" << endl;
        return 0;
    }

    // Available restaurants print kar rahe hain
    cout << "Found Restaurants:" << endl;
    for (auto restaurant : restaurantList) {
        cout << " - " << restaurant->getName() << endl;
    }

    // User ek restaurant select karta hai
    tomato->selectRestaurant(user, restaurantList[0]);
    cout << "Selected restaurant: " << restaurantList[0]->getName() << endl;

    // User menu se items cart me add karta hai
    tomato->addToCart(user, "P1");
    tomato->addToCart(user, "P2");

    // Cart ka summary print karte hain
    tomato->printUserCart(user);

    // User immediate (Now) order place karta hai
    // Payment ke liye UPI strategy use ho rahi hai
    Order* order = tomato->checkoutNow(
        user,
        "Delivery",
        new UpiPaymentStrategy("1234567890")
    );

    // User payment karta hai
    // Payment success hone par notification aata hai
    tomato->payForOrder(user, order);

    // Cleanup – memory free kar rahe hain
    delete tomato;
    delete user;

    return 0;
}

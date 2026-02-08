#ifndef USER_H
#define USER_H

#include <string>
#include "Cart.h"

using namespace std;

// User class application ke user ko represent karti hai
// Har user ka apna ek Cart hota hai (Composition relationship)
class User {

private:
    int userId;        // unique user id
    string name;       // user ka naam
    string address;    // user ka address
    Cart* cart;        // user ka personal cart

public:
    // Constructor – user details set karta hai
    // Aur user ke liye naya Cart create karta hai
    User(int userId, const string& name, const string& address) {
        this->userId = userId;
        this->name = name;
        this->address = address;
        cart = new Cart(); // User owns the cart
    }

    // Destructor – cart ki memory free karta hai
    ~User() {
        delete cart;
    }

    // -------- Getters and Setters --------

    // User ka naam return karta hai
    string getName() const {
        return name;
    }

    // User ka naam update karta hai
    void setName(const string &n) {
        name = n;
    }

    // User ka address return karta hai
    string getAddress() const {
        return address;
    }

    // User ka address update karta hai
    void setAddress(const string &a) {
        address = a;
    }

    // User ka cart return karta hai
    Cart* getCart() const {
        return cart;
    }
};

#endif // USER_H

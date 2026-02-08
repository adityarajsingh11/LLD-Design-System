#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

using namespace std;

// MenuItem class ek food item ko represent karti hai
// Ye restaurant ke menu ka ek single item hota hai
class MenuItem {

private:
    string code;   // unique item code (e.g. PIZ01)
    string name;   // item ka naam
    int price;     // item ki price

public:
    // Constructor – menu item ki details set karta hai
    MenuItem(const string& code, const string& name, int price) {
        this->code = code;
        this->name = name;
        this->price = price;
    }

    // -------- Getters and Setters --------

    // Item code return karta hai
    string getCode() const {
        return code;
    }

    // Item code set karta hai
    void setCode(const string &c) {
        code = c;
    }

    // Item ka naam return karta hai
    string getName() const {
        return name;
    }

    // Item ka naam update karta hai
    void setName(const string &n) {
        name = n;
    }

    // Item ki price return karta hai
    int getPrice() const {
        return price;
    }

    // Item ki price update karta hai
    void setPrice(int p) {
        price = p;
    }
};

#endif // MENUITEM_H

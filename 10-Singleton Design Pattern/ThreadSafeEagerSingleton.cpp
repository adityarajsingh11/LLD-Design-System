#include<iostream>
using namespace std;

class Singleton {
private:
    // Static pointer jo SINGLE instance ko hold karega
    static Singleton* instance;

    // Private constructor
    // Bahar se koi new Singleton() nahi kar sakta
    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }

public:
    // Sirf instance return karta hai
    // Yaha koi check nahi hai (kyunki object pehle hi ban chuka hota hai)
    static Singleton* getInstance() {
        return instance;
    }
};

// EAGER INITIALIZATION
// Program start hote hi object create ho jaata hai
Singleton* Singleton::instance = new Singleton();

int main() {
    // Dono calls same instance return karengi
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    // Same memory address => true (1)
    cout << (s1 == s2) << endl;
}

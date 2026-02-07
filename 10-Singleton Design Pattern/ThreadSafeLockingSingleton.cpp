#include<iostream>
#include <mutex>      // mutex library for thread safety
using namespace std;

class Singleton {

private:
    // Static pointer → poore program me ek hi copy hoti hai
    static Singleton* instance;

    // Mutex → multiple threads ke beech race condition avoid karne ke liye
    static mutex mtx;

    // Private constructor
    // Iska matlab: koi bhi bahar se object create nahi kar sakta
    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }

public:
    // Static method → bina object ke call ho sakta hai
    static Singleton* getInstance() {

        // lock_guard automatically mutex lock karta hai
        // Yaha ensure ho raha hai ki ek time pe sirf ek thread hi andar aaye
        lock_guard<mutex> lock(mtx);  

        // Agar instance abhi tak bana hi nahi hai
        if (instance == nullptr) {

            // Tabhi new object create karo
            instance = new Singleton();
        }

        // Har baar wahi same instance return hoga
        return instance;
    }
};

// Static members ko class ke bahar initialize karna padta hai
// Shuru me koi object nahi hota → nullptr
Singleton* Singleton::instance = nullptr;

// Mutex ka ek hi shared object
mutex Singleton::mtx;

int main() {

    // First thread (ya call)
    // instance == nullptr → constructor call hoga
    Singleton* s1 = Singleton::getInstance();

    // Second call
    // instance already created → constructor call nahi hoga
    Singleton* s2 = Singleton::getInstance();

    // Dono pointers same object ko point kar rahe hain
    // Output: 1 (true)
    cout << (s1 == s2) << endl;

    return 0;
}

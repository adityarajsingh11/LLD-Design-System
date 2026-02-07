#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;   // Single object ka pointer
    static mutex mtx;             // Thread synchronization ke liye mutex

    // Private constructor => bahar se object nahi ban sakta
    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    // Double Check Locking approach (Thread-safe + Optimized)
    static Singleton* getInstance() {

        // First check: bina lock ke (fast path)
        if (instance == nullptr) {

            // Lock sirf tab lagate hain jab object exist nahi karta
            lock_guard<mutex> lock(mtx);

            // Second check: lock ke baad (safety ke liye)
            if (instance == nullptr) {
                instance = new Singleton(); // Sirf ek hi baar object banega
            }
        }
        return instance; // Same instance return hoga
    }
};
 
// Static members ka initialization
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    // Dono pointer same object ko point kar rahe honge
    cout << (s1 == s2) << endl; // Output: 1 (true)
}

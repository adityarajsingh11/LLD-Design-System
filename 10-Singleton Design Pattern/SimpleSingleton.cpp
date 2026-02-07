#include<iostream>
using namespace std;

class Singleton {

private:
    // Static pointer to hold the SINGLE instance of the class
    // Static is used so that this variable belongs to the class, not to any object
    static Singleton* instance;

    // Private constructor
    // So that no one can create object using: new Singleton()
    Singleton() {
        cout << "Singleton Constructor called" << endl;
    }

public:
    // Static method to access the single instance
    // Static because object may not exist yet
    static Singleton* getInstance() {

        // Check if instance is not created yet
        if(instance == nullptr) {

            // Create the object ONLY ONCE
            instance = new Singleton();
        }

        // Return the same instance every time
        return instance;
    }
};

// Static member initialization
// Initially no object is created, so set to nullptr
Singleton* Singleton::instance = nullptr;

int main() {

    // First call to getInstance()
    // instance == nullptr → true
    // So constructor will be called
    Singleton* s1 = Singleton::getInstance();

    // Second call to getInstance()
    // instance != nullptr → object already exists
    // Constructor will NOT be called
    Singleton* s2 = Singleton::getInstance();

    // Comparing both pointers
    // If Singleton works correctly, this will print 1 (true)
    cout << (s1 == s2) << endl;

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

/*
==================== BASE CLASS ====================
Car is an abstract base class.
It represents a generic car and defines a common interface
for all types of cars.

This class demonstrates:
1. Inheritance       → Child classes inherit Car
2. Abstraction       → Pure virtual functions
3. Dynamic Polymorphism → Virtual functions
*/
class Car {
protected:
    // Protected so that child classes can access them
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    // Constructor to initialize common car properties
    Car(string brand, string model) {
        this->brand = brand;
        this->model = model;
        this->isEngineOn = false;
        this->currentSpeed = 0;
    }

    // Common behavior for all cars
    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    /*
    -------- POLYMORPHISM --------
    Below methods are PURE VIRTUAL functions.
    They enforce child classes to provide their own implementations.
    */

    // Dynamic polymorphism (runtime)
    virtual void accelerate() = 0;

    // Static + Dynamic polymorphism (overloading + overriding)
    virtual void accelerate(int speed) = 0;

    // Dynamic polymorphism (runtime)
    virtual void brake() = 0;

    // Virtual destructor (important for base class pointers)
    virtual ~Car() {}
};

/*
==================== MANUAL CAR ====================
ManualCar IS-A Car
This class inherits from Car and provides its own
implementation of abstract methods.

Demonstrates:
- Inheritance
- Method overriding (dynamic polymorphism)
- Method overloading (static polymorphism)
*/
class ManualCar : public Car {
private:
    int currentGear; // Specific to ManualCar

public:
    // Constructor calls parent constructor
    ManualCar(string brand, string model) : Car(brand, model) {
        currentGear = 0;
    }

    // Method specific to ManualCar
    void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model
             << " : Shifted to gear " << currentGear << endl;
    }

    // Overriding accelerate() → Dynamic Polymorphism
    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model
                 << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model
             << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    // Overloading + Overriding accelerate(int)
    // Static + Dynamic Polymorphism together
    void accelerate(int speed) {
        if (!isEngineOn) {
            cout << brand << " " << model
                 << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += speed;
        cout << brand << " " << model
             << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    // Overriding brake() → Dynamic Polymorphism
    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model
             << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }
};

/*
==================== ELECTRIC CAR ====================
ElectricCar IS-A Car
Adds battery-related behavior.

Demonstrates:
- Inheritance
- Dynamic polymorphism
- Different implementation of same methods
*/
class ElectricCar : public Car {
private:
    int batteryLevel; // Specific to ElectricCar

public:
    ElectricCar(string brand, string model) : Car(brand, model) {
        batteryLevel = 100;
    }

    // ElectricCar specific method
    void chargeBattery() {
        batteryLevel = 100;
        cout << brand << " " << model
             << " : Battery fully charged!" << endl;
    }

    // Overriding accelerate() → Dynamic Polymorphism
    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model
                 << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        if (batteryLevel <= 0) {
            cout << brand << " " << model
                 << " : Battery dead! Cannot accelerate." << endl;
            return;
        }
        batteryLevel -= 10;
        currentSpeed += 15;
        cout << brand << " " << model
             << " : Accelerating to " << currentSpeed
             << " km/h. Battery at " << batteryLevel << "%." << endl;
    }

    // Overloading + Overriding accelerate(int)
    void accelerate(int speed) {
        if (!isEngineOn) {
            cout << brand << " " << model
                 << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        if (batteryLevel <= 0) {
            cout << brand << " " << model
                 << " : Battery dead! Cannot accelerate." << endl;
            return;
        }
        batteryLevel -= (10 + speed);
        currentSpeed += speed;
        cout << brand << " " << model
             << " : Accelerating to " << currentSpeed
             << " km/h. Battery at " << batteryLevel << "%." << endl;
    }

    // Overriding brake() → Dynamic Polymorphism
    void brake() {
        currentSpeed -= 15;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model
             << " : Regenerative braking! Speed is now "
             << currentSpeed << " km/h. Battery at "
             << batteryLevel << "%." << endl;
    }
};

/*
==================== MAIN FUNCTION ====================
Demonstrates:
- Runtime polymorphism using base class pointer
- Same interface, different behavior
*/
int main() {

    // Base class pointer pointing to ManualCar object
    Car* manualCar = new ManualCar("Ford", "Mustang");
    manualCar->startEngine();
    manualCar->accelerate();
    manualCar->accelerate();
    manualCar->brake();
    manualCar->stopEngine();

    cout << "----------------------" << endl;

    // Base class pointer pointing to ElectricCar object
    Car* electricCar = new ElectricCar("Tesla", "Model S");
    electricCar->startEngine();
    electricCar->accelerate();
    electricCar->accelerate();
    electricCar->brake();
    electricCar->stopEngine();

    // Proper cleanup (important with polymorphism)
    delete manualCar;
    delete electricCar;

    return 0;
}

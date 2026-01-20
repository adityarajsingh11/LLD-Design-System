#include <iostream>
#include <string>

using namespace std;

/*
Dynamic Polymorphism:
Same interface (Car) but different behavior
based on object type at runtime.
*/ 
class Car {
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string brand, string model) {
        this->brand = brand;
        this->model = model;
        this->isEngineOn = false;
        this->currentSpeed = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual ~Car() {}
};

// ---------------- Manual Car ----------------
class ManualCar : public Car {
private:
    int currentGear;

public:
    ManualCar(string brand, string model) : Car(brand, model) {
        currentGear = 0;
    }

    void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model
             << " : Shifted to gear " << currentGear << endl;
    }

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

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model
             << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }
};

// ---------------- Electric Car ----------------
class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(string brand, string model) : Car(brand, model) {
        batteryLevel = 100;
    }

    void chargeBattery() {
        batteryLevel = 100;
        cout << brand << " " << model
             << " : Battery fully charged!" << endl;
    }

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

    void brake() {
        currentSpeed -= 15;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model
             << " : Regenerative braking! Speed is now "
             << currentSpeed << " km/h. Battery at "
             << batteryLevel << "%." << endl;
    }
};

// ---------------- Main ----------------
int main() {

    Car* manualCar = new ManualCar("Suzuki", "WagonR");
    manualCar->startEngine();
    manualCar->accelerate();
    manualCar->accelerate();
    manualCar->brake();
    manualCar->stopEngine();

    cout << "----------------------" << endl;

    Car* electricCar = new ElectricCar("Tesla", "Model S");
    electricCar->startEngine();
    electricCar->accelerate();
    electricCar->accelerate();
    electricCar->brake();
    electricCar->stopEngine();

    delete manualCar;
    delete electricCar;

    return 0;
}

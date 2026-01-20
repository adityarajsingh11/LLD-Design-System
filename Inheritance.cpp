#include <iostream>
#include <string>

using namespace std;

/*
Inheritance example:
Parent class -> Car
Child classes -> ManualCar, ElectricCar
*/
class Car {
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m) {
        brand = b;
        model = m;
        isEngineOn = false;
        currentSpeed = 0;
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

    virtual ~Car() {}
};

// ---------------- Manual Car ----------------
class ManualCar : public Car {
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m) {
        currentGear = 0;
    }

    void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model
             << " : Shifted to gear " << currentGear << endl;
    }
};

// ---------------- Electric Car ----------------
class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m) {
        batteryLevel = 100;
    }

    void chargeBattery() {
        batteryLevel = 100;
        cout << brand << " " << model
             << " : Battery fully charged!" << endl;
    }
};

// ---------------- Main ----------------
int main() {

    ManualCar* manualCar = new ManualCar("Suzuki", "WagonR");
    manualCar->startEngine();
    manualCar->shiftGear(1);
    manualCar->accelerate();
    manualCar->brake();
    manualCar->stopEngine();
    delete manualCar;

    cout << "----------------------" << endl;

    ElectricCar* electricCar = new ElectricCar("Tesla", "Model S");
    electricCar->chargeBattery();
    electricCar->startEngine();
    electricCar->accelerate();
    electricCar->brake();
    electricCar->stopEngine();
    delete electricCar;

    return 0;
}

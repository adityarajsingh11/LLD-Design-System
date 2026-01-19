#include <iostream>
#include <string>

using namespace std;

/*
ABSTRACTION:
- This abstract class exposes WHAT actions a car can perform
- It hides HOW those actions are implemented
*/
class Car {
public:
    virtual void startEngine() = 0;
    virtual void changeGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;

    virtual ~Car() {}
};

/*
Concrete class:
- Implements HOW the car actually works
*/
class SportsCar : public Car {
private:
    string brand;
    string model;
    int speed;
    int gear;
    bool engineOn;

public:
    SportsCar(string b, string m) {
        brand = b;
        model = m;
        speed = 0;
        gear = 0;
        engineOn = false;
    }

    void startEngine() {
        engineOn = true;
        cout << brand << " " << model << " : Engine Started" << endl;
    }

    void changeGear(int g) {
        if (!engineOn) {
            cout << "Engine is OFF. Cannot change gear." << endl;
            return;
        }
        gear = g;
        cout << "Gear changed to " << gear << endl;
    }

    void accelerate() {
        if (!engineOn) {
            cout << "Engine is OFF. Cannot accelerate." << endl;
            return;
        }
        speed += 30;
        cout << "Speed increased to " << speed << " km/h" << endl;
    }

    void brake() {
        speed -= 20;
        if (speed < 0) speed = 0;
        cout << "Brake applied. Speed: " << speed << " km/h" << endl;
    }

    void stopEngine() {
        engineOn = false;
        speed = 0;
        gear = 0;
        cout << "Engine Stopped" << endl;
    }
};

int main() {

    Car* car = new SportsCar("BMW", "M4");

    car->startEngine();
    car->changeGear(1);
    car->accelerate();
    car->brake();
    car->stopEngine();

    delete car;
    return 0;
}

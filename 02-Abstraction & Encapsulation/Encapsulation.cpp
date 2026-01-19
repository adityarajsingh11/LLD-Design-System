#include <iostream>
#include <string>

using namespace std;

/*
ENCAPSULATION:
- Data + Behaviour wrapped inside a class
- Private data provides security
*/
class SportsCar {
private:
    string brand;
    string model;
    int speed;
    bool engineOn;
    string tyreCompany;

public:
    SportsCar(string b, string m) {
        brand = b;
        model = m;
        speed = 0;
        engineOn = false;
        tyreCompany = "MRF";
    }

    // Getter
    int getSpeed() {
        return speed;
    }

    // Setter with validation (Data Security)
    void setTyreCompany(string company) {
        tyreCompany = company;
    }

    string getTyreCompany() {
        return tyreCompany;
    }

    void startEngine() {
        engineOn = true;
        cout << "Engine Started" << endl;
    }

    void accelerate() {
        if (!engineOn) {
            cout << "Engine OFF. Cannot accelerate." << endl;
            return;
        }
        speed += 20;
        cout << "Speed: " << speed << " km/h" << endl;
    }

    void brake() {
        speed -= 20;
        if (speed < 0) speed = 0;
        cout << "Speed after brake: " << speed << endl;
    }
};

int main() {

    SportsCar car("Audi", "R8");

    car.startEngine();
    car.accelerate();

    // car.speed = 500; ❌ Not allowed (Data Security)

    cout << "Current Speed: " << car.getSpeed() << endl;
    cout << "Tyre Company: " << car.getTyreCompany() << endl;

    car.setTyreCompany("Michelin");

    cout << "Updated Tyre Company: " << car.getTyreCompany() << endl;

    return 0;
}

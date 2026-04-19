#include <iostream>
using namespace std;


class Fuel {
protected:
    string fuelType;

public:
    Fuel() { fuelType = ""; }
    Fuel(string f) { fuelType = f; }
};


class Brand {
protected:
    string brandName;

public:
    Brand() { brandName = ""; }
    Brand(string b) { brandName = b; }
};

class Car : public Fuel, public Brand {
public:
    Car() : Fuel(), Brand() {}

    Car(string f, string b) : Fuel(f), Brand(b) {}

    void input() {
        cout << "Enter Brand: ";
        cin >> brandName;
        cout << "Enter Fuel: ";
        cin >> fuelType;
    }

    void display() {
        cout << "Brand: " << brandName
             << ", Fuel: " << fuelType << endl;
    }
};

int main() {


    cout << "Static Method:\n";

    Car c[2] = {
        Car("Petrol", "Maruti"),
        Car("Electric", "Tesla")
    };

    for (int i = 0; i < 2; i++) {
        c[i].display();
    }

    int n;
    cout << "\nEnter number of cars: ";
    cin >> n;

    Car *d = new Car[n];

    for (int i = 0; i < n; i++) {
        cout << "\nCar " << i+1 << ":\n";
        d[i].input();
    }

    cout << "\nDynamic Method Output:\n";
    for (int i = 0; i < n; i++) {
        d[i].display();
    }

    delete[] d;

    return 0;
}

#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
public:
    float temp;

    Celsius(float t = 0) {
        temp = t;
    }

    operator Fahrenheit();
};

class Fahrenheit {
public:
    float temp;

    Fahrenheit(float t = 0) {
        temp = t;
    }


    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }


    bool operator==(Celsius c) {
        return (temp == ((c.temp * 9 / 5) + 32));
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main() {
    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;
    cout << "Celsius to Fahrenheit: " << f1.temp << endl;

    Celsius c2;
    c2 = f1;
    cout << "Fahrenheit to Celsius: " << c2.temp << endl;

    if (f1 == c1)
        cout << "Temperatures are equal" << endl;
    else
        cout << "Temperatures are NOT equal" << endl;

    float arr[3];
    arr[0] = c1.temp;
    arr[1] = c2.temp;
    arr[2] = 30;

    cout << "\nArray elements: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

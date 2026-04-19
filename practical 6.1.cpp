#include <iostream>
using namespace std;


class Shape {
protected:
    float radius;

public:
    void setRadius(float r) {
        radius = r;
    }

    float getRadius() {
        return radius;
    }
};

class Circle : public Shape {
public:
    float area() {
        return 3.14 * radius * radius;
    }
};

int main() {

    int n;
    cout << "Enter number of circles (static): ";
    cin >> n;

    Circle c[10];

    for (int i = 0; i < n; i++) {
        float r;
        cout << "Enter radius: ";
        cin >> r;
        c[i].setRadius(r);
    }

    cout << "\nAreas (Static):\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i+1 << ": " << c[i].area() << endl;
    }



    int m;
    cout << "\nEnter number of circles (dynamic): ";
    cin >> m;

    Circle *d = new Circle[m];

    for (int i = 0; i < m; i++) {
        float r;
        cout << "Enter radius: ";
        cin >> r;
        d[i].setRadius(r);
    }

    cout << "\nAreas (Dynamic):\n";
    for (int i = 0; i < m; i++) {
        cout << "Circle " << i+1 << ": " << d[i].area() << endl;
    }

    delete[] d;

    return 0;
}

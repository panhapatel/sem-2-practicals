#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "Area not defined\n";
    }
};

class Rectangle : public Shape {
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    void area() {
        cout << "Rectangle Area: " << length * width << endl;
    }
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    void area() {
        cout << "Circle Area: " << 3.14 * radius * radius << endl;
    }
};

int main() {


    Shape* arr[2];
    arr[0] = new Rectangle(5, 4);
    arr[1] = new Circle(3);

    cout << "Using Static Array:\n";
    for (int i = 0; i < 2; i++) {
        arr[i]->area();
    }


    int n = 2;
    Shape** shapes = new Shape*[n];

    shapes[0] = new Rectangle(6, 2);
    shapes[1] = new Circle(5);

    cout << "\nUsing Dynamic Storage:\n";
    for (int i = 0; i < n; i++) {
        shapes[i]->area();
    }

    return 0;
}

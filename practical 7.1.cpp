#include <iostream>
using namespace std;

class Calculator {
    float r1, r2, r3;

public:

    void add(int a, int b) {
        r1 = a + b;
    }

    void add(float a, float b) {
        r2 = a + b;
    }


    void add(int a, float b) {
        r3 = a + b;
    }

    void display() {
        cout << "Results:\n";
        cout << r1 << endl;
        cout << r2 << endl;
        cout << r3 << endl;
    }
};

int main() {
    Calculator c;

    c.add(2, 3);
    c.add(2.5f, 3.5f);
    c.add(4, 2.5f);

    c.display();

    return 0;
}

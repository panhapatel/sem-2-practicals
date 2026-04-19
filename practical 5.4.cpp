#include <iostream>
using namespace std;


ostream& currency(ostream& out) {
    out << "₹ ";
    return out;
}

int main() {
    string name[] = {"Amit", "Riya", "Karan"};
    int marks[] = {85, 92, 78};
    float fees[] = {1500.5, 2000.75, 1800.0};

    cout << "Name\tMarks\tFees\n";
    cout << "-----------------------------\n";

    for (int i = 0; i < 3; i++) {
        cout << name[i] << "\t"
             << marks[i] << "\t"
             << currency << fees[i] << endl;
    }

    return 0;
}

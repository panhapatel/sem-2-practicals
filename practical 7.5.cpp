#include <iostream>
using namespace std;

class Grading {
protected:
    float marks;

public:
    Grading(float m) {
        marks = m;
    }

    virtual void computeGrade() = 0;
};

class Undergraduate : public Grading {
public:
    Undergraduate(float m) : Grading(m) {}

    void computeGrade() {
        cout << "Undergraduate Grade: ";
        if (marks >= 75) cout << "A";
        else if (marks >= 60) cout << "B";
        else if (marks >= 50) cout << "C";
        else cout << "Fail";
        cout << endl;
    }
};


class Postgraduate : public Grading {
public:
    Postgraduate(float m) : Grading(m) {}

    void computeGrade() {
        cout << "Postgraduate Grade: ";
        if (marks >= 80) cout << "A";
        else if (marks >= 70) cout << "B";
        else if (marks >= 60) cout << "C";
        else cout << "Fail";
        cout << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Grading* students[10];

    for (int i = 0; i < n; i++) {
        int type;
        float marks;

        cout << "\n1. Undergraduate  2. Postgraduate\n";
        cout << "Enter type: ";
        cin >> type;

        cout << "Enter marks: ";
        cin >> marks;

        if (type == 1)
            students[i] = new Undergraduate(marks);
        else
            students[i] = new Postgraduate(marks);
    }

    cout << "\n--- Results ---\n";
    for (int i = 0; i < n; i++) {
        students[i]->computeGrade();
    }

    return 0;
}

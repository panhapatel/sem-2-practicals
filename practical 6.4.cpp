#include <iostream>
using namespace std;

class Account {
protected:
    int accNo;
    float balance;

public:
    Account(int a, float b) {
        accNo = a;
        balance = b;
    }

    void deposit(float amt) {
        balance += amt;
    }

    void withdraw(float amt) {
        if (amt <= balance)
            balance -= amt;
        else
            cout << "Insufficient Balance\n";
    }

    void display() {
        cout << "Acc No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Savings : public Account {
    float interest;

public:
    Savings(int a, float b, float i) : Account(a, b) {
        interest = i;
    }

    void display() {
        Account::display();
        cout << "Interest: " << interest << "%" << endl;
    }
};

class Current : public Account {
    float overdraft;

public:
    Current(int a, float b, float o) : Account(a, b) {
        overdraft = o;
    }

    void withdraw(float amt) {
        if (amt <= balance + overdraft)
            balance -= amt;
        else
            cout << "Overdraft limit exceeded\n";
    }

    void display() {
        Account::display();
        cout << "Overdraft: " << overdraft << endl;
    }
};

int main() {
    Savings s(101, 1000, 5);
    Current c(102, 2000, 500);

    s.deposit(500);
    s.withdraw(200);
    s.display();

    cout << endl;

    c.deposit(1000);
    c.withdraw(2500);
    c.display();

    return 0;
}

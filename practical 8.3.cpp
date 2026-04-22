#include <iostream>
using namespace std;

string logs[20];
int logIndex = 0;

void addLog(string msg) {
    logs[logIndex++] = msg;
}

class BankAccount {
    float balance;

public:
    BankAccount(float b) {
        balance = b;
    }

    void deposit(float amount) {
        addLog("Entered deposit()");
        if (amount <= 0) {
            throw "Invalid deposit amount!";
        }
        balance += amount;
        addLog("Deposit successful");
    }

    void withdraw(float amount) {
        addLog("Entered withdraw()");
        if (amount > balance) {
            throw "Insufficient balance!";
        }
        balance -= amount;
        addLog("Withdrawal successful");
    }

    float getBalance() {
        return balance;
    }
};

void performTransaction(BankAccount &acc) {
    addLog("Entered performTransaction()");

    acc.deposit(100);
    acc.withdraw(500);

    addLog("Exiting performTransaction()");
}

int main() {
    BankAccount acc(200);

    try {
        addLog("Entered main()");
        performTransaction(acc);
        addLog("Exiting main()");
    }
    catch (const char* msg) {
        addLog("Exception caught in main()");
        cout << "Exception: " << msg << endl;
    }


    cout << "\n--- Transaction Logs (Stack Unwinding) ---\n";
    for (int i = 0; i < logIndex; i++) {
        cout << logs[i] << endl;
    }

    return 0;
}

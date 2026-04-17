#include <iostream>
using namespace std;

class Account
{
private:
    int accNo;
    string name;
    double balance;
    static int total;

public:
    void create()
    {
        cout << "Account No: ";
        cin >> accNo;
        cout << "Name: ";
        cin >> name;
        cout << "Balance: ";
        cin >> balance;
        total++;
    }

    void display()
    {
        cout << accNo << "  " << name << "  " << balance << endl;
    }

    int getNo()
    {
        return accNo;
    }

    void transfer(Account &a)
    {
        double amt;
        cout << "Amount: ";
        cin >> amt;

        if (amt > 0 && balance >= amt)
        {
            balance -= amt;
            a.balance += amt;
            cout << "Transfer Done\n";
        }
        else
        {
            cout << "Invalid Transfer\n";
        }
    }

    static void showTotal()
    {
        cout << "\nTotal Accounts: " << total << endl;
    }
};

int Account::total = 0;

int main()
{
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    Account acc[10];

    // create
    for (int i = 0; i < n; i++)
        acc[i].create();

    // display
    for (int i = 0; i < n; i++)
        acc[i].display();

    // transfer
    int x, y;
    cout << "\nFrom: ";
    cin >> x;
    cout << "To: ";
    cin >> y;

    Account *p = NULL, *q = NULL;

    for (int i = 0; i < n; i++)
    {
        if (acc[i].getNo() == x)
            p = &acc[i];
        if (acc[i].getNo() == y)
            q = &acc[i];
    }

    if (p != NULL && q != NULL)
        p->transfer(*q);
    else
        cout << "Account not found\n";

    // final display
    cout << "\nUpdated:\n";
    for (int i = 0; i < n; i++)
        acc[i].display();

    Account::showTotal();

    return 0;
}



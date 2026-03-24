#include <iostream>
#include <cmath>
#include<string>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:

    Loan() {
        loanID = 1234;
        applicantName = "Mahek";
        loanAmount = 20000;
        annualInterestRate = 7;
        tenureMonths = 9;
    }


    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }


    double calculateEMI() {
        double monthlyRate = annualInterestRate / (12 * 100);
        double emi = (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) /
                     (pow(1 + monthlyRate, tenureMonths) - 1);
        return emi;
    }


    void display() {
        cout << "\nLoan Details:\n";
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Tenure (Months): " << tenureMonths << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};

int main() {

    Loan loan1;
    loan1.display();


    Loan loan2(101, "Rahul", 500000, 8, 36);
    loan2.display();

    return 0;
}

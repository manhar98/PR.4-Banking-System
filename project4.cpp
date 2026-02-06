#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
protected:
    int accNo;
    char name[50];
    double balance;

public:
    BankAccount() {
        accNo = 0;
        strcpy(name, "");
        balance = 0;
    }

    void setAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cin.ignore();

        cout << "Enter Account Holder Name: ";
        cin.getline(name, 50);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    double getBalance() {
        return balance;
    }

    void display() {
        cout << "\nAccount No: " << accNo << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    void setSavings() {
        setAccount();
        cout << "Enter Interest Rate (%): ";
        cin >> interestRate;
    }

    void calculateInterest() {
        double interest = balance * interestRate / 100;
        cout << "Interest Earned: " << interest << endl;
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    void setChecking() {
        setAccount();
        cout << "Enter Overdraft Limit: ";
        cin >> overdraftLimit;
    }

    void checkOverdraft(double amount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawal Successful (Overdraft Allowed)\n";
        } else {
            cout << "Overdraft Limit Exceeded!\n";
        }
    }
};

class FixedDepositAccount : public BankAccount {
    int duration;   
    double rate;

public:
    void setFD() {
        setAccount();
        cout << "Enter Duration (months): ";
        cin >> duration;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
    }

    void calculateInterest() {
        double interest = balance * rate * duration / 100;
        cout << "Fixed Deposit Interest: " << interest << endl;
    }
};

int main() {
    int choice;
    double amount;

    do {
        cout << "\n--- Bank Account Menu ---\n";
        cout << "1. Savings Account\n";
        cout << "2. Checking Account\n";
        cout << "3. Fixed Deposit Account\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            SavingsAccount s;
            s.setSavings();
            s.display();

            cout << "Enter Deposit Amount: ";
            cin >> amount;
            s.deposit(amount);

            s.calculateInterest();
            s.display();
            break;
        }

        case 2: {
            CheckingAccount c;
            c.setChecking();
            c.display();

            cout << "Enter Withdraw Amount: ";
            cin >> amount;
            c.checkOverdraft(amount);

            c.display();
            break;
        }

        case 3: {
            FixedDepositAccount f;
            f.setFD();
            f.display();

            f.calculateInterest();
            break;
        }

        case 4:
            cout << "Thank You! Program End.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}

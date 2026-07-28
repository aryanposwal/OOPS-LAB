#include <iostream>
#include <string>

using namespace std;

class ATM {
private:
    string accountNumber;
    int pin;
    double balance;

public:
    ATM(string accNum, int initialPin, double initialBalance) {
        accountNumber = accNum;
        pin = initialPin;
        balance = initialBalance;
    }

    bool authenticate(int enteredPin) {
        if (enteredPin == pin) {
            return true;
        }
        return false;
    }

    void checkBalance() {
        cout << "\n-------------------------" << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-------------------------" << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nSuccessfully deposited $" << amount << endl;
            checkBalance();
        } else {
            cout << "\nInvalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\nSuccessfully withdrew $" << amount << endl;
            checkBalance();
        } else if (amount > balance) {
            cout << "\nError: Insufficient balance!" << endl;
        } else {
            cout << "\nInvalid withdrawal amount!" << endl;
        }
    }

    void changePin(int oldPin, int newPin) {
        if (oldPin == pin) {
            pin = newPin;
            cout << "\nPIN successfully changed!" << endl;
        } else {
            cout << "\nError: Incorrect old PIN!" << endl;
        }
    }
};

int main() {
    ATM myATM("12345", 1234, 1000.00);

    int enteredPin;
    cout << "=== Welcome to the ATM ===" << endl;
    cout << "Enter your 4-digit PIN: ";
    cin >> enteredPin;

    if (!myATM.authenticate(enteredPin)) {
        cout << "Incorrect PIN. Access Denied!" << endl;
        return 0;
    }

    int choice;
    double amount;
    int oldPin, newPin;

    do {
        cout << "\n--- ATM Menu ---" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Change PIN" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                myATM.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myATM.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myATM.withdraw(amount);
                break;
            case 4:
                cout << "Enter old PIN: ";
                cin >> oldPin;
                cout << "Enter new PIN: ";
                cin >> newPin;
                myATM.changePin(oldPin, newPin);
                break;
            case 5:
                cout << "\nThank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
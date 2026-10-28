#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string customerName;
    double balance;
    vector<string> transactions;

public:
    Account(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        customerName = name;
        balance = initialBalance;
        transactions.push_back("Account opened with initial balance: " + to_string(initialBalance));
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.push_back("Deposited: " + to_string(amount));
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions.push_back("Withdrew: " + to_string(amount));
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void displayAccountInfo() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Customer Name: " << customerName << "\n";
        cout << "Current Balance: $" << balance << "\n";
    }

    void showTransactions() {
        cout << "\n--- Transaction History ---\n";
        for (const string &t : transactions) {
            cout << "- " << t << "\n";
        }
    }
};

int main() {
    int accNo;
    string name;
    double initBalance;

    cout << "--- Create New Bank Account ---\n";
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Customer Name: ";
    cin >> name;
    cout << "Enter Initial Balance: ";
    cin >> initBalance;

    Account myAccount(accNo, name, initBalance);

    int choice;
    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. View Account Details\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double amt;
                cout << "Enter amount to deposit: ";
                cin >> amt;
                myAccount.deposit(amt);
                break;
            }
            case 2: {
                double amt;
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                myAccount.withdraw(amt);
                break;
            }
            case 3:
                myAccount.displayAccountInfo();
                break;
            case 4:
                myAccount.showTransactions();
                break;
            case 5:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
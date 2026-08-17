#include <iostream>
using namespace std;

/*
----------------------------------------------------------
BankAccount Class
Demonstrates usage of 'this' pointer
----------------------------------------------------------
*/
class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double bal) {
        this->accountHolder = name;
        this->balance = bal;
    }

    // Deposit (Method chaining enabled)
    BankAccount* deposit(double amount) {
        this->balance += amount;
        return this;
    }

    // Withdraw (Method chaining enabled)
    BankAccount* withdraw(double amount) {
        if(this->balance >= amount)
            this->balance -= amount;
        else
            cout << "Insufficient Balance\n";

        return this;
    }

    void display() const {
        cout << "Account Holder: "
             << accountHolder << endl;
        cout << "Current Balance: "
             << balance << endl;
    }
};

int main() {

    string name;
    double balance;

    cout << "Enter account holder name: ";
    cin >> name;

    cout << "Enter initial balance: ";
    cin >> balance;

    BankAccount acc(name, balance);

    // Method chaining
    acc.deposit(500)->withdraw(300)->display();

    return 0;
}

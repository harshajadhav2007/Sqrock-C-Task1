#include <iostream>
#include <string>
#include <iomanip> // For formatting currency output

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    // Constructor
    BankAccount(std::string name, double initial_balance = 0.0) {
        owner = name;
        balance = initial_balance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited $" << std::fixed << std::setprecision(2) << amount << std::endl;
        } else {
            std::cout << "Error: Deposit amount must be positive." << std::endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Error: Insufficient funds!" << std::endl;
        } else if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive." << std::endl;
        } else {
            balance -= amount;
            std::cout << "Successfully withdrew $" << std::fixed << std::setprecision(2) << amount << std::endl;
        }
    }

    // Method to display balance
    void displayBalance() const {
        std::cout << "Account Owner: " << owner << std::endl;
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }
};

int main() {
    std::string name;
    std::string choice;
    double amount;

    std::cout << "--- Welcome to the Mini Bank System ---" << std::endl;
    std::cout << "Enter account holder name: ";
    std::getline(std::cin, name);

    // Create account object
    BankAccount account(name);

    while (true) {
        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Deposit Money" << std::endl;
        std::cout << "2. Withdraw Money" << std::endl;
        std::cout << "3. Check Balance" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Select an option (1-4): ";
        std::cin >> choice;

        if (choice == "1") {
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            account.deposit(amount);
        } 
        else if (choice == "2") {
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            account.withdraw(amount);
        } 
        else if (choice == "3") {
            account.displayBalance();
        } 
        else if (choice == "4") {
            std::cout << "Thank you for banking with us. Goodbye!" << std::endl;
            break;
        } 
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

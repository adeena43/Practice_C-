/*Bank Account Management System: Design a bank account management system that can handle
 multiple account types such as savings account, current account, and fixed deposit account.
  Implement functionalities to add new accounts, close accounts, deposit money, withdraw money, and display account details.
 Ensure that account information is stored in a file and can be read and updated as needed.*/
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

class Account {
protected:
    int account_number;
    double balance;
    std::string account_type;
    std::string owner_name;

public:
    Account(int acc_number, double bal, std::string acc_type, std::string owner)
        : account_number(acc_number), balance(bal), account_type(acc_type), owner_name(owner) {}

    void deposit(double amount) {
        balance += amount;
        update_account_details();
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            update_account_details();
            return true;
        } else {
            std::cout << "Insufficient funds" << std::endl;
            return false;
        }
    }

    void display() {
        std::cout << "Account Number: " << account_number << std::endl;
        std::cout << "Owner Name: " << owner_name << std::endl;
        std::cout << "Account Type: " << account_type << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

    void update_account_details() {
        std::ifstream inFile("accounts.txt");
        std::ofstream outFile("temp.txt");

        int accNum;
        double bal;
        std::string accType, ownerName;
        while (inFile >> accNum >> bal >> accType >> ownerName) {
            if (accNum == account_number) {
                bal = balance;
            }
            outFile << std::setw(10) << accNum << std::setw(10) << bal << std::setw(15) << accType << std::setw(20) << ownerName << std::endl;
        }

        inFile.close();
        outFile.close();
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
    }

    static void add_account_to_file(int acc_number, double bal, std::string acc_type, std::string owner_name) {
        std::ofstream outFile("accounts.txt", std::ios::app);
        outFile << std::setw(10) << acc_number << std::setw(10) << bal << std::setw(15) << acc_type << std::setw(20) << owner_name << std::endl;
        outFile.close();
    }

    static void remove_account_from_file(int acc_number) {
        std::ifstream inFile("accounts.txt");
        std::ofstream outFile("temp.txt");

        int accNum;
        double bal;
        std::string accType, ownerName;
        while (inFile >> accNum >> bal >> accType >> ownerName) {
            if (accNum != acc_number) {
                outFile << std::setw(10) << accNum << std::setw(10) << bal << std::setw(15) << accType << std::setw(20) << ownerName << std::endl;
            }
        }

        inFile.close();
        outFile.close();
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
    }
};

class SavingsAccount : public Account {
private:
    double interest_rate;

public:
    SavingsAccount(int acc_number, double bal, std::string owner, double rate)
        : Account(acc_number, bal, "Savings", owner), interest_rate(rate) {}
};

class CurrentAccount : public Account {
private:
    double overdraft_limit;

public:
    CurrentAccount(int acc_number, double bal, std::string owner, double limit)
        : Account(acc_number, bal, "Current", owner), overdraft_limit(limit) {}
};

int main() {
   
    Account::add_account_to_file(1001, 5000, "Savings", "John Doe");
    Account::add_account_to_file(2001, 10000, "Current", "Jane Smith");

    std::cout << "Before removal:" << std::endl;
    Account::remove_account_from_file(1001);
    Account::remove_account_from_file(2001);
    std::cout << "After removal:" << std::endl;

    return 0;
}

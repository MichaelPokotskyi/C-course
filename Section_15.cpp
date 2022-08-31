#include <iostream>
#include <vector>
#include <string>
#include "Section_15.h"

// Running by S15() from main ->

void s15() {
    cout.precision(2);
    cout << fixed;
    string str;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{ "Larry" });
    accounts.push_back(Account{ "Moe", 2000 });
    accounts.push_back(Account{ "Curly", 5000 });

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{ "Superman" });
    sav_accounts.push_back(Savings_Account{ "Batman", 2000 });
    sav_accounts.push_back(Savings_Account{ "Wonderwoman", 5000, 5.0 });

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    cin >> str;

    return 0;
}


//Account.cpp ****
Account::Account(std::string name, double balance)
    : name{ name }, balance{ balance } {
}

bool Account::deposit(double amount) {
    if (amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    }
    else
        return false;
}

double Account::get_balance() const {
    return balance;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}

// Account_Util.cpp
// Displays Account objects in a  vector of Account objects 
void display(const std::vector<Account>& accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}


// Helper functions for Savings Account class

// Displays Savings Account objects in a  vector of Savings Account objects 
void display(const std::vector<Savings_Account>& accounts) {
    std::cout << "\n=== Savings Accounts ====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts ==========================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraw(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ======================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Savings_Account.cpp
Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account{ name, balance }, int_rate{ int_rate } {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate / 100);
    return Account::deposit(amount);
}

std::ostream& operator<<(std::ostream& os, const Savings_Account& account) {
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

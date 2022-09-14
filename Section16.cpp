#include "Section16.h"
#include <iostream>                                                             
#include <vector>
using namespace std;

//Accopunt.cpp
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

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}

//Checking Account.cpp
Checking_Account::Checking_Account(std::string name, double balance)
    : Account{ name, balance } {
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

std::ostream& operator<<(std::ostream& os, const Checking_Account& account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << "]";
    return os;
}

//Savings Account.cpp
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
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "]";
    return os;
}

//Trust Accouint.cpp
Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{ name, balance, int_rate }, num_withdrawals{ 0 } {

}

// Deposit additional $50 bonus when amount >= $5000
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}

// Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent))
        return false;
    else {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate
        << "%, withdrawals: " << account.num_withdrawals << "]";
    return os;
}



//Account Util.cpp
// Displays Account objects in a  vector of Account objects 
void display(const std::vector<Account>& accounts) {
    std::cout << "\n=== Accounts===========================================" << std::endl;
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
    std::cout << "\n=== Savings Accounts=====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts===========================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraw(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts=======================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Helper functions for Checking Account class

// Displays Checking Account objects in a  vector of Checking Account objects 
void display(const std::vector<Checking_Account>& accounts) {
    std::cout << "\n=== Checking Accounts=====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Checking Account object in the vector
void deposit(std::vector<Checking_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Checking Accounts===========================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Checking Account object in the vector
void withdraw(std::vector<Checking_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Checking Accounts=======================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Helper functions for Trust Account class

// Displays Trust Account objects in a  vector of Trust Account objects 
void display(const std::vector<Trust_Account>& accounts) {
    std::cout << "\n=== Trust Accounts=====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Trust Account object in the vector
void deposit(std::vector<Trust_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Trust Accounts===========================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Trust Account object in the vector
void withdraw(std::vector<Trust_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Trust Accounts=======================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

//ALL TESTS
void s16() {
    cout.precision(2);
    cout << fixed;

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

    // Checking

    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account{});
    check_accounts.push_back(Checking_Account{ "Kirk" });
    check_accounts.push_back(Checking_Account{ "Spock", 2000 });
    check_accounts.push_back(Checking_Account{ "Bones", 5000 });

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust

    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account{});
    trust_accounts.push_back(Trust_Account{ "Athos", 10000, 5.0 });
    trust_accounts.push_back(Trust_Account{ "Porthos", 20000, 4.0 });
    trust_accounts.push_back(Trust_Account{ "Aramis", 30000 });

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i = 1; i <= 5; i++)
        withdraw(trust_accounts, 1000);

}
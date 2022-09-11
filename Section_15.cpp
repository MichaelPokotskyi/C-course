#include <iostream>
#include <vector>
#include <string>
#include "Section_15.h"

using namespace std;

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

std::ostream& operator<<(ostream& os, const Account& account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}

// Account_Util.cpp****
// Displays Account objects in a  vector of Account objects 
void display(const vector<Account>& accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(vector<Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(vector<Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Helper functions for Savings Account class
// Displays Savings Account objects in a vector of Savings Account objects 
void display(const vector<Savings_Account>& accounts) {
    std::cout << "\n=== Savings Accounts ====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}
// Helper functions for Cheking Account class
// Displays Cheking Account objects in a  vector of Cheking Account objects 
void display(const vector<Checking_Account>& accounts) {
    std::cout << "\n=== Checking Accounts ====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Helper functions for Trust Account class
// Displays Trust Account objects in a vector of Trust Account objects 
void display(const vector<Trust_Account>& accounts) {
    std::cout << "\n=== Trust Accounts ====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts ==========================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraw(vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ======================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Helper functions for Cheking_Account class
void deposit(vector<Checking_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Checking Accounts ==========================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

void withdraw(vector<Checking_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Checking Accounts ======================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Helper functions for Trust_Account class
void deposit(vector<Trust_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Trust Accounts ==========================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

void withdraw(vector<Trust_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Trust Accounts ======================" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

std::ostream& operator<<(ostream& os, const Savings_Account& account) {
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

// Savings_Account.cpp****
Savings_Account::Savings_Account(string name, double balance, double int_rate)
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




//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//

//Challenge section
//For Checking_Account
Checking_Account::Checking_Account(string name, double balance)
    : Account{ name, balance } {
}

//1.50 fees applied
bool Checking_Account::withdraw(double widthdraw) {
    if (balance - (widthdraw + fees) >= 0) {
        balance -= widthdraw + fees;
        return true;
    }
    else
        return false;
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

std::ostream& operator<<(ostream& os, const Checking_Account& account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << "]";
    return os;
}

//For Trust_Account
Trust_Account::Trust_Account(string name, double balance)
    : Account{ name, balance } {
}

//1.50 fees applied as in Checking Account, plus other rules
bool Trust_Account::withdraw(double widthdraw) {
    if (balance - (widthdraw + fees) >= 0 && widthdraw <= balance/3 && count <=2) {
        balance -= widthdraw + fees;
        count++;
        return true;
    }
    else
        return false;
}

bool Trust_Account::deposit(double amount) {
    if (amount >= 5000) {
        amount += bonus;
    }
    return Account::deposit(amount);
}

std::ostream& operator<<(ostream& os, const Trust_Account& account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << "]";
    return os;
}

// Running by S15() from main ->

int s15() {
    cout.precision(2);
    cout << fixed;
    //string str;

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

    vector<Checking_Account> ch_accounts;
    ch_accounts.push_back(Checking_Account{});
    ch_accounts.push_back(Checking_Account{ "Checking_1" });
    ch_accounts.push_back(Checking_Account{ "Checking_2", 2000 });
    ch_accounts.push_back(Checking_Account{ "Checking_3", 5000 });

    display(ch_accounts);
    deposit(ch_accounts, 1000);
    withdraw(ch_accounts, 2000);

    vector<Trust_Account> tr_accounts;
    tr_accounts.push_back(Trust_Account{});
    tr_accounts.push_back(Trust_Account{ "Trust_1" });
    tr_accounts.push_back(Trust_Account{ "Trust_2", 1000 });
    tr_accounts.push_back(Trust_Account{ "Trust_3", 4000 });
    
    display(tr_accounts);
    deposit(tr_accounts, 1500);
    withdraw(tr_accounts, 2000);
    
    Trust_Account Trust_4{ "Trust_4", 40000 };
    cout << Trust_4.withdraw(4000) << endl;
    cout << Trust_4.withdraw(3000) << endl;
    cout << Trust_4.withdraw(2000) << endl;
    cout << Trust_4.withdraw(1000) << endl;
    

    //cin >> str;
    return 0;
}
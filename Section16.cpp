#include "Section16.h"
#include <iostream>                                                             
#include <vector>
using namespace std;


//Printable interface implementation
ostream& operator<<(ostream& os, const Printable& obj) {
    obj.print(os);
    return os;
}

//Accopunt.cpp
Account::Account(string name, double balance)
    : name{ name }, balance{ balance } {
}

bool Account::deposit(double amount) {
    if (amount < 0)
        return false;
    else {
        balance += amount;
        //cout << "account type /Account/ " << name << " deposited by " << amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        //ONLY this function will be called for any object inherited from Account class (Base Class reference) by static polymorphism.
        //cout << "Account class withdraw function" << endl;
        return true;
    }
    else
        return false;
}

//Checking Account.cpp
Checking_Account::Checking_Account(string name, double balance)
    : Account{ name, balance } {
}

bool Checking_Account::deposit(double amount) {
    if (amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    cout << "Checking Account class withdraw function" << endl;
    return Account::withdraw(amount);
}

//Savings Account.cpp
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


//Trust Accouint.cpp
Trust_Account::Trust_Account(string name, double balance, double int_rate)
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
        cout << "Trust Account class withdraw function" << endl;
        return Savings_Account::withdraw(amount);
    }
}


//Account Util.cpp
// Displays Account objects in a  vector of Account objects 
void display(const vector<Account>& accounts) {
    cout << "\n=== Accounts===========================================" << endl;
    for (const auto& acc : accounts)
        cout << acc << endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(vector<Account>& accounts, double amount) {
    cout << "\n=== Depositing to Accounts =================================" << endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            cout << "Deposited " << amount << " to " << acc << endl;
        else
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(vector<Account>& accounts, double amount) {
    cout << "\n=== Withdrawing from Accounts ==============================" << endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            cout << "Withdrew " << amount << " from " << acc << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << acc << endl;
    }
}

// Withdraw amount from each Account object in the vector
// for exampling Base Class pointer functionality, 
// accepting vector of pointers to Account objects and working with them by dereferencing
void withdraw(vector<Account*> accounts, double amount) {
    cout << "\n=== Withdrawing from Accounts ==============================" << endl;
for (auto acc : accounts) {
        if ((*acc).withdraw(amount))
            cout << "Withdraw " << amount << " from " << *acc << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << *acc << endl;
    }
}

// Helper functions for Savings Account class

// Displays Savings Account objects in a  vector of Savings Account objects 
void display(const vector<Savings_Account>& accounts) {
    cout << "\n=== Savings Accounts=====================================" << endl;
    for (const auto& acc : accounts)
        cout << acc << endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(vector<Savings_Account>& accounts, double amount) {
    cout << "\n=== Depositing to Savings Accounts===========================" << endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            cout << "Deposited " << amount << " to " << acc << endl;
        else
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraw(vector<Savings_Account>& accounts, double amount) {
    cout << "\n=== Withdrawing from Savings Accounts=======================" << endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            cout << "Withdrew " << amount << " from " << acc << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << acc << endl;
    }
}

// Helper functions for Checking Account class

// Displays Checking Account objects in a  vector of Checking Account objects 
void display(const vector<Checking_Account>& accounts) {
    cout << "\n=== Checking Accounts=====================================" << endl;
    for (const auto& acc : accounts)
        cout << acc << endl;
}

// Deposits supplied amount to each Checking Account object in the vector
void deposit(vector<Checking_Account>& accounts, double amount) {
    cout << "\n=== Depositing to Checking Accounts===========================" << endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            cout << "Deposited " << amount << " to " << acc << endl;
        else
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
    }
}

// Withdraw supplied amount from each Checking Account object in the vector
void withdraw(vector<Checking_Account>& accounts, double amount) {
    cout << "\n=== Withdrawing from Checking Accounts=======================" << endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            cout << "Withdrew " << amount << " from " << acc << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << acc << endl;
    }
}

// Helper functions for Trust Account class

// Displays Trust Account objects in a  vector of Trust Account objects 
void display(const vector<Trust_Account>& accounts) {
    cout << "\n=== Trust Accounts=====================================" << endl;
    for (const auto& acc : accounts)
        cout << acc << endl;
}

// Deposits supplied amount to each Trust Account object in the vector
void deposit(vector<Trust_Account>& accounts, double amount) {
    cout << "\n=== Depositing to Trust Accounts===========================" << endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            cout << "Deposited " << amount << " to " << acc << endl;
        else
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
    }
}

// Withdraw supplied amount from each Trust Account object in the vector
void withdraw(vector<Trust_Account>& accounts, double amount) {
    cout << "\n=== Withdrawing from Trust Accounts=======================" << endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            cout << "Withdrew " << amount << " from " << acc << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << acc << endl;
    }
}

//ALL TESTS
void s16() {
    cout.precision(2);
    cout << fixed;
    Account* p1 = new Account("Acc", 2000);
    Account* p2 = new Savings_Account("Sav_Acc", 2000);
    Account* p3 = new Checking_Account("Check_Acc", 2000);
    Account* p4 = new Trust_Account("Tr_Acc", 2000);
    vector<Account*> acc {p1, p2, p3, p4}; // Base Class pointer VECTOR created
    
    withdraw(acc, 200.00);

    for (auto a: acc) { //teting dynamic polymorphism in loop
        cout << *a << endl;
    }
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    /*
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
        */

}
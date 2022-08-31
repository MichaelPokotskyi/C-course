#pragma once
#ifndef _Section_15_H_
#define _Section_15_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Running by S15() from main ->
void s15();

// Account.h ****
class Account {
    friend ostream& operator<<(ostream& os, const Account& account);
private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    // Account(std::string name = "Unamed Account", double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

// Savings_Account.h ****
// Savings Account is a type of Account
// adds an interest rate
// Withdraw - same as a regular account
// Deposit:
// Amount supplied to deposit will be incremented by (amount * int_rate/100) 
// and then the updated amount will be deposited
class Savings_Account : public Account {
    friend ostream& operator<<(ostream& os, const Savings_Account& account);
private:
    static constexpr const char* def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    // Inherits the Account::withdraw methods
};

// Account_Util.h ****
// Utility helper functions for Account class

void display(const vector<Account>& accounts);
void deposit(vector<Account>& accounts, double amount);
void withdraw(vector<Account>& accounts, double amount);

// Utility helper functions for Savings Account class

void display(const vector<Savings_Account>& accounts);
void deposit(vector<Savings_Account>& accounts, double amount);
void withdraw(vector<Savings_Account>& accounts, double amount);

//Challenge section
class Checking_Account : public Account {
    friend ostream& operator<<(ostream& os, const Savings_Account& account);
private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double fees = 1.5;
public:

    //bool Deposit(double amount);

};

class Trust_Account : public Account {

};

#endif
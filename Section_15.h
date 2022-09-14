#pragma once
#ifndef _Section_15_H_
#define _Section_15_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;



// Account.h ****
class Account {
    friend ostream& operator<<(ostream& os, const Account& account);
private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    string name;
    double balance;
public:
    Account(string name = def_name, double balance = def_balance);
    //Account(string name = "Unamed Account", double balance = 0.0);
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

//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//

//Challenge section
class Checking_Account : public Account {
    friend ostream& operator<<(ostream& os, const Checking_Account& account);
private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
protected:
    static constexpr double fees = 1.5;
public:
    Checking_Account(string name = def_name, double balance = def_balance);
    bool withdraw(double widthraw);
    bool deposit(double amount);
};

class Trust_Account : public Account {
    friend ostream& operator<<(ostream& os, const Trust_Account& account);
private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double bonus = 50.0;
    static constexpr double fees = 1.5;
protected:
    int count{0};
public:
    Trust_Account(string name = def_name, double balance = def_balance);
    bool withdraw(double widthraw);
    bool deposit(double amount);
};

// Account_Util.h ****
// Utility helper functions for Account class
//void display(const vector<Account>& accounts);
//void deposit(vector<Account>& accounts, double amount);
//void withdraw(vector<Account>& accounts, double amount);

// Utility helper functions for Savings Account class
//void display(const vector<Savings_Account>& accounts);
//void deposit(vector<Savings_Account>& accounts, double amount);
//void withdraw(vector<Savings_Account>& accounts, double amount);

// Utility helper functions for Checking Account class
//void display(const vector<Checking_Account>& accounts);
//void deposit(vector<Checking_Account>& accounts, double amount);
//void withdraw(vector<Checking_Account>& accounts, double amount);

// Utility helper functions for Trust Account class
//void display(const vector<Trust_Account>& accounts);
//void deposit(vector<Trust_Account>& accounts, double amount);
//void withdraw(vector<Trust_Account>& accounts, double amount);

// Running by S15() from main ->
int s15();
         

#endif _Section_15_H_
#pragma once
#ifndef _Section16_H_
#define _Section16_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Account.h
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
    bool deposit(double amount);
    bool withdraw(double amount);
};

//Checking Account.h
class Checking_Account : public Account {
    friend ostream& operator<<(ostream& os, const Checking_Account& account);
private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(string name = def_name, double balance = def_balance);
    bool withdraw(double);
    // Inherits the Account::deposit method
};

//Savings Account.h
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
    // Inherits the Account::withdraw method
};

//Trust Account.h
class Trust_Account : public Savings_Account {
    friend ostream& operator<<(ostream& os, const Trust_Account& account);
private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int num_withdrawals;
public:
    Trust_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    // Deposits of $5000.00 or more will receive $50 bonus
    bool deposit(double amount);

    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    bool withdraw(double amount);
};

void s16();

#endif _Section16_H_
/*
//Account_Util.h
// Utility helper functions for Account class

void display(const std::vector<Account>& accounts);
void deposit(std::vector<Account>& accounts, double amount);
void withdraw(std::vector<Account>& accounts, double amount);

// Utility helper functions for Savings Account class

void display(const std::vector<Savings_Account>& accounts);
void deposit(std::vector<Savings_Account>& accounts, double amount);
void withdraw(std::vector<Savings_Account>& accounts, double amount);

// Utility helper functions for Checking Account class
void display(const std::vector<Checking_Account>& accounts);
void deposit(std::vector<Checking_Account>& accounts, double amount);
void withdraw(std::vector<Checking_Account>& accounts, double amount);

// Utility helper functions for Trust Account class
void display(const std::vector<Trust_Account>& accounts);
void deposit(std::vector<Trust_Account>& accounts, double amount);
void withdraw(std::vector<Trust_Account>& accounts, double amount);
*/
#pragma once
#ifndef _Section16_H_
#define _Section16_H_

using namespace std;

#include <iostream>
#include <string>
#include <vector>

//call from main
void s16();

// Printable interface
class Printable
{
    friend ostream& operator<<(ostream& os, const Printable& obj);
public:
    virtual void print(ostream& os) const = 0;
    virtual ~Printable() = default;
};


//Account.h
class Account : public Printable {
private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    string name;
    double balance;
public:
    Account(string name = def_name, double balance = def_balance);
    virtual void print(ostream& os) const override {
        os << "Account class" << endl << "Account name: " << name << endl << "Rest of balance : " << balance << endl;
    }
    //Base class metods to be inherited by derived classes
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    virtual ~Account() = default;
};

//Checking Account.h
class Checking_Account : public Account {
private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(string name = def_name, double balance = def_balance);
    virtual void print(ostream& os) const override {
        os << "Checking Account class" << endl << "Account name: " << name << endl << "Rest of balance : " << balance << endl;
    }
    // Inherits methods from Account base class
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual ~Checking_Account() = default;
};

//Savings Account.h
class Savings_Account : public Account {
private:
    static constexpr const char* def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual void print(ostream& os) const override {
        os << "Savings Account class" << endl << "Account name: " << name << endl << "Rest of balance : " << balance << endl;
    }
    // Inherits methods from Account base class
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual ~Savings_Account() = default;
};

//Trust Account.h
class Trust_Account : public Savings_Account {
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
    virtual void print(ostream& os) const override {
        os << "Trust Account class" << endl << "Account name: " << name << endl << "Rest of balance : " << balance << endl;
    }
    // Inherits methods from Account base class
    virtual bool deposit(double amount) override; // Deposits of $5000.00 or more will receive $50 bonus
    virtual bool withdraw(double amount) override; // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    virtual ~Trust_Account() = default;
 };



#endif _Section16_H_

//Account_Util.h
// Utility helper functions for Account class
/*
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
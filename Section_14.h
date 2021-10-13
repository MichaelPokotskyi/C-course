#pragma once
#ifndef _Section_14_H_
#define _Section_14_H_

using namespace std;

class Mystring
{
private:
	char *str; // pointer to a char[] that holds a C-style string

public:
	Mystring(); // no-args constructor
	Mystring(const char* s); // string constructor
	Mystring(const Mystring &source); // copy constructor
	Mystring(Mystring &&source);// move constructor
	~Mystring(); // destructor

	//Section 14 challenge

	//Overloads as member functions:
	// overload "="
	Mystring &operator=(const Mystring& rhs);

	//overload "-"
	Mystring operator-() const;

	//overload "=="
	bool &operator==(const Mystring &rhs);

	//overload "!="
	bool& operator!=(const Mystring& rhs);

	//overload "<"
	bool& operator<(const Mystring& rhs);

	//overload ">"
	bool& operator>(const Mystring& rhs);

	//overload "+"
	Mystring &operator+(const Mystring& rhs);

	//overload "+="
	//overload "*"
	//overload "*="
	//overload "++"
	//overload "--"


	void display() const;
	int get_length() const; // getters
	const char* get_str() const;
};
#endif
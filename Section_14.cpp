#pragma once
#pragma warning(disable : 4996);
#pragma warning(disable : 6387);
#include <iostream>
#include <cstring>
#include "Section_14.h"

using namespace std;

//No args constructor
Mystring::Mystring() : str{nullptr} {
	str = new char[1];
	*str = '\0';
}

//One arg constructor 
Mystring::Mystring(const char* s) : str{nullptr} {
	if (s == nullptr) {
		str = new char[1];
		*str = '\0';
	}
	else {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
}

//Copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr} {
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

//Move constructor
Mystring::Mystring(Mystring&& source) : str{source.str} {
	source.str = nullptr;
}

//Destructor
Mystring::~Mystring() {
	delete [] str;
}
//Overloads as MEMBER FUNCTIONS:
//Overload "=" opeartor (assignment)
Mystring &Mystring::operator=(const Mystring &rhs) {
if (this == &rhs) {
		return *this;
		delete[] this->str;
	} 
	str = new char[strlen(rhs.str) + 1];
	strcpy(this->str, rhs.str);
	return *this;
}

//Overload "-" opeartor (unary minus)
Mystring Mystring :: operator-() const {
	char* buf = new char[strlen(str) + 1];
	strcpy(buf, str);
	for (size_t i = 0; i < strlen(buf); i++) {
		buf[i] = tolower(buf[i]);
	}
	Mystring temp{ buf };
	delete[] buf;
	return temp;
}

//Overload "==" opeartor (equal)
bool &Mystring :: operator==(const Mystring &rhs) {
	//char *buf1 = new char[strlen(this->str)];
	bool tt = true;
	if (strcmp(this->str, rhs.str) != 0) 
	{
		return tt;
	}
	else 
	{
		tt = false;
		return tt;
	}
}

//Overload "!=" opeartor (not equal)
bool& Mystring :: operator!=(const Mystring& rhs) {
	bool tt = true;
	if (strcmp(this->str, rhs.str) == 0)
	{
		return tt;
	}
	else
	{
		tt = false;
		return tt;
	}
}

//Overload "<" opeartor (lexically greater)
bool& Mystring :: operator<(const Mystring& rhs) {
	bool tt = true;
	if (this->str < rhs.str) 
	{
		return tt;
	}
	else 
	{
		tt = false;
		return tt;
	}
}

//Overload ">" opeartor (lexically less)
bool& Mystring :: operator>(const Mystring& rhs) {
	bool tt = true;
	if (this->str > rhs.str)
	{
		return tt;
	}
	else
	{
		tt = false;
		return tt;
	}
}

//Overload "+" operator (concatenation)
Mystring &Mystring::operator+(const Mystring& rhs) {
	cout << this->str << endl;
	cout << strlen(this->str) << endl;
	cout << rhs.str << endl;
	cout << strlen(rhs.str) << endl;
	int tt = strlen(this->str) + strlen(rhs.str);
	cout << tt << endl;
	
	char *buf = new char[tt]; // if TT then strlen=20
	for (int i = 0; i < tt; i++)
	{
		if (i < strlen(this->str))
		{
			buf[i] = this->str[i]; 
		}
		else if (i > strlen(this->str))
		{
			buf[i] = rhs.str[i];
		}
	}
	buf[tt]='\0';
	//strcpy(buf, rhs.str);
	cout << buf << endl;
	
	

	
	/*
	str = new char[strlen(rhs.str) + 1];
	strcpy(this->str, rhs.str);
	return *this;
	*/
	Mystring ret{};
	return ret;
}

//Overload "+=" operator (concatenation)
//Overload "*" operator (repeat)
//Overload "*=" operator (repeat)

//Getters implementation
void Mystring::display() const {
	cout << str << " : " << get_length() << endl;
}

int Mystring::get_length() const {
	return strlen(str);
}

const char* Mystring::get_str() const {
	return str;
}
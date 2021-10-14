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
Mystring Mystring::operator+(const Mystring& rhs) {
	int tt = strlen(this->str) + strlen(rhs.str);
	char *con = new char[tt]; 
	int count{0};
	for (int i = 0; i < strlen(this->str); i++)
	{
		con[i] = this->str[i];
		count++;
	}
	for (int i = 0; i < strlen(rhs.str); i++) 
	{
		con[count] = rhs.str[i];
		count++;
	}
	con[count] = '\0';

	Mystring ret{ con };
	return ret;
	delete[] con;
}

//Overload "+=" operator (concatenation)
Mystring Mystring::operator+=(const Mystring& rhs) {}

//Overload "*" operator (repeat)
Mystring Mystring::operator*(const Mystring& rhs) {}

//Overload "*=" operator (repeat)
Mystring Mystring::operator*=(const Mystring& rhs) {}

//Getters implementation
void Mystring::display() const {
	cout << this->str << " : " << get_length() << endl;
}

int Mystring::get_length() const {
	return strlen(str);
}

const char* Mystring::get_str() const {
	return str;
}
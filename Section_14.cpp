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

//Example Overload as GLOBAL (FRIEND) FUNCTIONS:
//overload "++"
Mystring operator++(const Mystring& rhs) {
	char* buf = new char[strlen(rhs.str) + 1];
	strcpy(buf, rhs.str);
	for (size_t i = 0; i < strlen(buf); i++) {
		buf[i] = toupper(buf[i]);
	}
	Mystring temp{ buf };
	delete[] buf;
	return temp;
}
//overload "--"
Mystring operator--(const Mystring& rhs) {
	char* buf = new char[strlen(rhs.str) + 1];
	strcpy(buf, rhs.str);
	for (size_t i = 0; i < strlen(buf); i++) {
		buf[i] = tolower(buf[i]);
	}
	Mystring temp{ buf };
	delete[] buf;
	return temp;
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
	char *con = new char[strlen(this->str) + strlen(rhs.str)];
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
Mystring Mystring::operator+=(const Mystring& rhs) {
	char* con = new char[(strlen(this->str) * 2) + strlen(rhs.str)];
	int count{0};
	for (int i = 0; i < strlen(this->str); i++)
	{
	con[i] = this->str[i]; // first symbol
	con[i + strlen(this->str)] = this->str[i];// second first symbol
	count+=2; // step plus two
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

//Overload "*" operator (repeat)
Mystring Mystring::operator*(const int &a) {
	int count{ 0 };
	//check if a = 0 or < 0
	if (a <= 0 ) 
	{
		cout << "Cannot multiply by value <= 0" << endl;
			return *this;
	}
	else {
		char* con = new char[strlen(this->str) * a];

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < strlen(this->str); j++)
			{
				con[count] = this->str[j];
				count++;
			}
		}
		con[count] = '\0';
		Mystring ret{ con };
		return ret;
		delete[]con;
	}
}

//Overload "*=" operator (repeat)
Mystring Mystring::operator*=(const Mystring& rhs) {
	Mystring ret{};
	return ret;
}

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
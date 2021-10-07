#pragma once
#pragma warning(disable : 4996);
#include <iostream>
#include <cstring>
#include "Section_14.h"

using namespace std;

// no args constructor
Mystring::Mystring()
	: str{nullptr} {
	str = new char[1];
	*str = '\0';
}

//Overloaded constructor
Mystring::Mystring(const char* s) 
	:str{nullptr} {
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
	str = new char[strlen(str) + 1];
	strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring(Mystring&& source) noexcept : str{source.str} {
	source.str = nullptr;
}

//Destructor
Mystring::~Mystring() {
	delete [] str;
}

//Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
if (this == &rhs) {
		return *this;
		delete[] this->str;
	} 
	str = new char[strlen(rhs.str) + 1];
	strcpy(this->str, rhs.str);
	return *this;
}

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
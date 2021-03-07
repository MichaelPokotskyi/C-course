#pragma once
#include <vector>
#include <iostream>
using namespace std;
// Section 9 challenge re written with functions.

void menu();
void choise(char, vector<signed>);
void print(vector<signed>);
void add(vector<signed>);
void disp_Ave(vector<signed>);
void disp_Smallest(vector<signed>);
void disp_Largest(vector<signed>);
void quit();

bool q = true;

void startNumbers() 
{
	
	//char ch{};
	menu();
}

void menu()
{
	char a;
	static vector<signed> vec{};
	signed add{ 0 }, sum{ 0 }, smallest{ 0 }, biggest{ 0 };
	double ave{};

	while (q) {
		cout << "Your choise:\n";
		cout <<
			"P - Print numbers\n"
			"A - Add number to the list\n"
			"M - Display average of the list\n"
			"S - Find smallest\n"
			"L - Find largest\n"
			"Q - Quit\n";
		cin >> a;
		choise(a, vec);
	}
}
	//--------------------------------------------------------//
		/*switch (choise)
		{
		case 'p':
		case 'P':
			if (vec.size() == 0) {
				cout << "\n[] - list size is zero\n";
			}
			else
			{
				cout << "\n[";
				for (unsigned i{ 0 }; i < vec.size(); ++i)
				{
					if (i != vec.size() - 1) { cout << vec[i] << " "; }
					else { cout << vec[i]; }
				}
				cout << "]\n";
			}
			break;
		case 'a':
		case 'A':
			cout << "\nEnter your number: \n";
			cin >> add;
			vec.push_back(add);
			cout << "\nYou added number : " << add << "\n";
			break;
		case 'm':
		case 'M':
			if (vec.size() == 0) {
				cout << "\n[] - list size is zero\n";
			}
			else
			{
				for (unsigned i{ 0 }; i < vec.size(); ++i)
				{
					sum += vec[i];
				}
				ave = (double)(sum) / vec.size();
				cout << "\nList average value: " << ave << "\n";
			}
			break;
		case 's':
		case 'S':
			if (vec.size() == 0) {
				cout << "\n[] - list size is zero\n";
			}
			else
			{
				for (unsigned i{ 1 }; i < vec.size(); ++i)
				{
					smallest = vec[0];
					if (vec[i] < smallest) { smallest = vec[i]; }
				}
				cout << "\nSmallest number in your list is: " << smallest << "\n";
			}
			break;
		case 'l':
		case 'L':
			if (vec.size() == 0) {
				cout << "\n[] - list size is zero\n";
			}
			else
			{
				for (unsigned i{ 1 }; i < vec.size(); ++i)
				{
					biggest = vec[0];
					if (vec[i] > biggest) { biggest = vec[i]; }
				}
				cout << "\nLargest number in your list is: " << biggest << "\n";
			}
			break;
		case 'q':
		case 'Q':
			cout << "Goodbye\n";
			break;
		default: cout << "\nIllegal choise, try again.\n";
		}
	
}*/

void choise(char a, vector<signed> vec)
{
	if (a == 'p' || a == 'P') {print(vec);}
	else if (a == 'a' || a == 'A') {add(vec);}
	else if (a == 'm' || a == 'M') { disp_Ave(vec);}
	else if (a == 's' || a == 'S') { disp_Smallest(vec); }
	else if (a == 'l' || a == 'L') { disp_Largest(vec); }
	else if (a == 'q' || a == 'Q') { quit(); }
	else cout << "\nIllegal choise, try again.\n";
	menu();
}

void print(vector<signed> vec)
{ 
	if (vec.size() == 0) {cout << "\n[] - list size is zero\n";}
	else
	{
		cout << "\n[";
		for (unsigned i{ 0 }; i < vec.size(); ++i)
		{
			if (i != vec.size() - 1) { cout << vec[i] << " "; }
			else { cout << vec[i]; }
		}
		cout << "]\n";
	}
menu();
}

void add(vector<signed> vec) 
{ 
	int add{};
	cout << "\nEnter your number: \n";
	cin >> add;
	vec.push_back(add);
	cout << "\nYou added number : " << add << "\n";
	menu(); 
}
void disp_Ave(vector<signed> vec) {}
void disp_Smallest(vector<signed> vec) {}
void disp_Largest(vector<signed> vec) {}

void quit() 
{
	q = false;
	cout << "\n See you later!";
}
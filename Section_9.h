#pragma once
using namespace std;

#include <vector>
#include <iostream>

void Numbers() {

	vector<signed> vec{};
	char choise{};

	do {
		signed add{ 0 }, sum{ 0 }, smallest{ 0 }, biggest{ 0 };
		double ave{};

		cout << "\nYour choise:\n";
		cout <<
			"P - print numbers\n"
			"A - add number to the list\n"
			"M - display average of the list\n"
			"S - find smallest\n"
			"L - find largest\n"
			"Q - quit\n";
		cin >> choise;
		switch (choise)
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
	} while (choise != 'q' && choise != 'Q');
}

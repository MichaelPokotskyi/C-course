#pragma once

using namespace std;


int Convert()
{
	int cents{ 0 };
	cout << "Enter cents amount: ";
	cin >> cents;

	cout << "Dollars: " << cents / 100 << "\n";
	cents -= (100 * (cents / 100));
	cout << "Quaters: " << cents / 25 << "\n";
	cents -= (25 * (cents / 25));
	cout << "Dimes: " << cents / 10 << "\n";
	cents -= (10 * (cents / 10));
	cout << "Nickles: " << cents / 5 << "\n";
	cents -= (5 * (cents / 5));
	cout << "Pennies: " << cents / 1 << "\n";

	return 0;
}
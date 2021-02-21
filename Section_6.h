#pragma once

#include <iostream>
using namespace std;

void FCCServ() {

	int const per_small{ 25 };
	int const per_big{ 35 };
	const double tax{ 0.06 };
	const int valid{ 30 };
	const string asterics{ "**********************************\n" };

	int small_r{ 0 };
	int big_r{ 0 };

	cout << "Estimate!\n";
	cout << "Enter # of big rooms: ";
	cin >> big_r;
	cout << "Enter # of small rooms: ";
	cin >> small_r;
	cout << "Price per big room - " << per_big << endl;
	cout << "Price per small room - " << per_small << endl;
	cout << "Tax - " << tax * 100 << "%" << endl;

	//calculations
	double total_no_tax = (double)big_r * per_big + small_r * per_small;
	double total_w_tax = (total_no_tax * tax) + total_no_tax;

	cout << asterics;
	cout << "Total estimate before tax: " << total_no_tax << endl;
	cout << "Tax: " << tax * total_no_tax << endl;
	cout << "Total estimate + tax: " << total_w_tax << endl;
	cout << "Esimate valid " << valid << " days.\n";
	cout << asterics;

}

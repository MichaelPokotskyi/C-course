#pragma once

#include <iostream>
#include <vector>

using namespace std;

void Vector() {

	vector <int> vector1{};
	vector <int> vector2{};
	vector <vector<int>> vector_2d{};
	/*{
		{0, 0},
		{0, 0}
	};*/

	vector1.push_back(10);
	vector1.push_back(20);
	cout << "Vector #1 Element #1 " << vector1.at(0) << "\n";
	cout << "Vector #1 Element #2 " << vector1.at(1) << "\n";
	cout << "size V1 = " << vector1.size() << endl;

	vector2.push_back(100);
	vector2.push_back(200);
	cout << "Vector #2 Element #1 " << vector2.at(0) << "\n";
	cout << "Vector #2 Element #2 " << vector2.at(1) << "\n";
	cout << "size V2 = " << vector2.size() << endl;

	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);



	cout << "1st second iteration: \n" <<
		vector_2d.at(0).at(0) << "\n" <<
		vector_2d.at(0).at(1) << "\n" <<
		vector_2d.at(1).at(0) << "\n" <<
		vector_2d.at(1).at(1) << "\n";

	vector1.at(0) = 1000;

	cout << "2d second iteration: \n" <<
		vector_2d.at(0).at(0) << "\n" <<
		vector_2d.at(0).at(1) << "\n" <<
		vector_2d.at(1).at(0) << "\n" <<
		vector_2d.at(1).at(1) << "\n";

	cout << "Vector #1 Element #1 " << vector1.at(0) << "\n";
	cout << "Vector #1 Element #2 " << vector1.at(1) << "\n";
	cout << "size V1 = " << vector1.size() << endl;

}
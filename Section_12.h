#pragma once
#include <iostream>
#include <vector>
using namespace std;

void s12() {
	int *arr_ptr{nullptr};
	int size{};
	cout << "How big? ";
	cin >> size;
	arr_ptr = new int{ size };
	
	for (int i{0}; i < size; ++i) {
		(*arr_ptr).at(i) = i;
		cout << &arr_ptr[i] << " " <<  (*arr_ptr).at(i) << endl;
	}
//	char t{};
//	cin >> t;
}
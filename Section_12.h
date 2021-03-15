#pragma once
#include <iostream>
using namespace std;

void print(int[], size_t);
int* apply_all(int[], int, int[], int);

void s12() {
	/*
	int *arr_ptr{nullptr};
	int size{};
	cout << "How big? ";
	cin >> size;
	arr_ptr = new int{ size };

	for (int i{0}; i < size; ++i) {
		cout << &arr_ptr[i] << " " <<  arr_ptr[i] << endl;
	}
	*/
	
	const size_t array1_size{ 5 };
	const size_t array2_size{ 3 };

	int arr1[]{ 1, 2, 3, 4, 5 };
	int arr2[]{ 10, 20, 30 };

	cout << "Array 1: ";
	print(arr1, array1_size);

	cout << "Array 2: ";
	print(arr2, array2_size);

	int *results = apply_all(arr1, array1_size, arr2, array2_size);
	//constexpr size_t res{ array1_size * array2_size };
	size_t res{ array1_size * array2_size };

	cout << "Result: ";
	//print(results, res);

}

void print(int arr[], size_t size)
{
	cout << "[";
	for (size_t i{ 0 }; i < size; ++i)
	{
		if (i != size - 1)
		{
			cout << arr[i] << ", ";
		}
		else
		{
			cout << arr[i];
		}
	}
	cout << "]";
	cout << endl;
}

int* apply_all(int arr1[], int size1, int arr2[], int size2)
{
	return 0;
}
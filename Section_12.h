#pragma once
#include <iostream>
using namespace std;

void print(int arr[], size_t size);
int* apply_all(int arr1[], int size1, int arr2[], int size2);

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
	
	const int array1_size{ 5 };
	const int array2_size{ 3 };

	int arr1[]{ 1, 2, 3, 4, 5 };
	int arr2[]{ 10, 20, 30 };

	cout << "Array 1: ";
	print(arr1, array1_size);

	cout << "Array 2: ";
	print(arr2, array2_size);

	int *results = apply_all(arr1, array1_size, arr2, array2_size);
	int res{ array1_size * array2_size };

	cout << "Result: ";
	print(results, res);

	delete[] results;

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
	int size_new = size1 * size2;
	int* arr{nullptr};
	arr = new int[size_new];
	int count{0};
	for (size_t i{0}; i < size2; ++i)
	{
		for (size_t j{0}; j < size1; ++j)
		{
			arr[count] = (arr2[i] * arr1[j]);
				++count;
		}
	}
	return arr;
}
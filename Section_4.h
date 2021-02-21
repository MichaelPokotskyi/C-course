#pragma once
#include <iostream>
using std::cout;
using std::cin;

int Second() {
    return 0;
}

int First() {
    int fNumber;
    cout << "Enter number btw 1 - 100:\n";
    cin >> fNumber;
    cout << "Number is: " << fNumber;
    return 0;
}
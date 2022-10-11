#pragma once
using namespace std;
#include <iostream>
#include <memory>
#include <vector>

//class TEST
class Test {
private:
    int data;
public:
    Test() : data{ 0 } { cout << "\tTest constructor (" << data << ")" << endl; }
    Test(int data) : data{ data } { cout << "\tTest constructor with Int (" << data << ")" << endl; }
    int get_data() const { return data; } //getter func
    ~Test() { cout << "\tTest destructor (" << data << ")" << endl; }
};

// func prototypes
int s17();
unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>> &vec, int num);
void display17(const vector<shared_ptr<Test>>& vec);
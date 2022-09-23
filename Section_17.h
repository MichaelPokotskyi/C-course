#pragma once
using namespace std;
#include <iostream>
#include <memory>
#include <vector>


// func prototypes
int s17();
unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>>& vec, int num);
void display17(const vector<shared_ptr<Test>>& vec);

//class TEST
class Test {
private:
    int data;
public:
    Test() : data{ 0 } { cout << "\tTest constructor (" << data << ")" << endl; }
    Test(int data) : data{ data } { cout << "\tTest constructor (" << data << ")" << endl; }
    int get_data() const { return data; } //getter func
    ~Test() { cout << "\tTest destructor (" << data << ")" << endl; }
};

//func implementation
unique_ptr<vector<shared_ptr<Test>>> make() {

    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    return vec_ptr;
}
void fill(vector<shared_ptr<Test>>& vec, int num) {}
void display17(const vector<shared_ptr<Test>>& vec){}
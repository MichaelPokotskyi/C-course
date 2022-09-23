using namespace std;
#include "Section_17.h"

//func implementation
unique_ptr<vector<shared_ptr<Test>>> make() {

    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    return vec_ptr;
}
void fill(vector<shared_ptr<Test>>& vec, int num) {}
void display17(const vector<shared_ptr<Test>>& vec) {}

int s17() {
	// function S17 called from main, testing
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data points do you want to enter: ";
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display17(*vec_ptr);
    return 0;
}


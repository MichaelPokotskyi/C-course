using namespace std;
#include "Section_17.h"

int s17() {
	// function S17 calledc from main
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display17(*vec_ptr);
    return 0;
}


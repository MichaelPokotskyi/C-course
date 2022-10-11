#include "Section_17.h"
#include <vector>

using namespace std;

//func implementation
unique_ptr<vector<shared_ptr<Test>>> make() {

    return make_unique<vector<shared_ptr<Test>>> ();
}

void fill(vector<shared_ptr<Test>> &vec, int num) {
    int el{};
    for (int i = 0; i < num; i++) {
        cout << "Enter "  << i + 1 << " point:" << endl;
        cin >> el;
        vec.push_back(make_shared<Test>(Test{el}));
    }
}

void display17(const vector<shared_ptr<Test>>& vec) {
   for (auto a : vec)
   {
      cout << "Data: " << a << endl;
   }
}

int s17() {
    // function S17 called from main, testing
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr = make();
    cout << "How many data points do you want to enter: ";
    int num;
    cin >> num;
    fill((*vec_ptr), num);
    //display17(*vec_ptr);
    return 0;
}

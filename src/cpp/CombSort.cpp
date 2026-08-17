// referenced resource given in README.md to understand comb sort
#include <iostream>
#include <vector>
using namespace std;
vector<int> CombSort(vector<int> vect) {
    // gap is size of vector
    int gap = vect.size();
    // shrink rate is 1.3 according to repo
    float shrink = 1.3;
    // bool condition for looping
    bool looping = true;
    while (looping) {
        // adjust gap
        gap = gap/shrink;
        // if gap < 1 then make it 1
        if (gap < 1) {
            gap = 1;
        }
        bool done = true;
        // for loop for that specific gap
        for (int i = 0; i < vect.size()-gap; i++) {
            // if out of order, switch them
            if (vect.at(i) > vect.at(i+gap)) {
                int temp = vect.at(i);
                vect.at(i) = vect.at(i+gap);
                vect.at(i+gap) = temp;
                // condition to show that it is not sorted
                done = false;
            }
        }
        // condition that it is sorted when each one was checked (gap = 1), so leave while loop
        if (done and gap == 1) {
            break;
        }
    }
    return vect;
}
int main() {
    // first random vector test
    vector<int> check1 = {3, 15, 4, 3, 2, 4, 14, 7, 10, 3, 20, 8, 4, 9, 5,};
    // show unsorted vector
    cout << "Initial Vector 1: ";
    for (int i = 0; i < check1.size(); i++) {
        if (i != check1.size()-1) {
            cout << check1.at(i) << ", ";
        }
        else {
            cout << check1.at(i) << endl;
        }
    }
    // show sorted vector
    vector<int> final1 = CombSort(check1);
    cout << "Sorted Vector 1: ";
    for (int i = 0; i < final1.size(); i++) {
        if (i != final1.size()-1) {
            cout << final1.at(i) << ", ";
        }
        else {
            cout << final1.at(i) << endl;
        }
    }
    // second random vector test
    vector<int> check2 = {10, 164, 20, 50, 70, 90, 1, 90, 14, 530, 439,};
    // show unsorted vector
    cout << "Initial Vector 2: ";
    for (int i = 0; i < check2.size(); i++) {
        if (i != check2.size()-1) {
            cout << check2.at(i) << ", ";
        }
        else {
            cout << check2.at(i) << endl;
        }
    }
    // show sorted vector
    vector<int> final2 = CombSort(check2);
    cout << "Sorted Vector 2: ";
    for (int i = 0; i < final2.size(); i++) {
        if (i != final2.size()-1) {
            cout << final2.at(i) << ", ";
        }
        else {
            cout << final2.at(i) << endl;
        }
    }
    cout << endl;
}
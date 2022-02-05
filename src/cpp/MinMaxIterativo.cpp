#include <iostream>

using namespace std;

int main() {

    int arr[] = {1, 5, -20, 6, 15};

    int min = arr[0];
    int max = arr[0];

    for(auto& i : arr) {
        if(i < min) min = i;
        else if(i > max) max = i;
    }

    cout << "Max = " + to_string(max) + "\nMin = " + to_string(min) << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int linear_search(vector<int> &nums, int target) {

    for (size_t i = 0; i < nums.size(); i++) {
        
        if(nums[i] == target)
            return i;
    }
    
    return -1;
}

int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 27, -1, 12, 999};
    int target;
    
    cout << "Enter the number you would like to search in the vector: ";
    cin >> target;
    cout << "\n";

    int pos = linear_search(nums, target);

    if(pos > -1) {
        cout << "Number found in the vector in the position: " << pos << endl;
    }
    else {
        cout << "Number not found in the vector." << endl;
    }

    return 0;
}
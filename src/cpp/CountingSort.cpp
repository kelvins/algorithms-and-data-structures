#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> counting_sort(vector<int>& nums) {
    
    
    // nums = {5, 0, 1, 2, 3, 5, 3, 0, 9, 4}
    // max = 9
    // The vector contains numbers between [0 .. max]
    auto max = *max_element(nums.begin(), nums.end());


    // Creates a vector with max + 1 positions to count occurrences of each element
    //            0  1  2  3  4  5  6  7  8  9   -> possible elements to occur in the vector nums
    // Counting = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    vector<int> counting(max+1);


    // Counts occurrences of each element
    // nums = {5, 0, 1, 2, 3, 5, 3, 0, 9, 4}
    //
    //             0  1  2  3  4  5  6  7  8  9
    // counting = {2, 1, 1, 2, 1, 2, 0, 0, 0, 1}
    //
    for(auto& i : nums) {
        counting[i]++;
    }


    // Now, counting = {2, 3, 4, 6, 7, 9, 9, 9, 9, 10}
    // It will be used to determine the positions of the elements in the ordered vector
    for (size_t i = 1; i < counting.size(); i++) {
        
        counting[i] += counting[i-1];
    }

    vector<int> sorted(nums.size());
    
    /*  

        The next loop places the numbers in their proper positions in the ordered vector
        i = iterates through the elements of nums
        counting[i] -1 is the position that element i must assume in the ordered vector

        The first 3 steps would be:

        nums = {5, 0, 1, 2, 3, 5, 3, 0, 9, 4}
        counting = {2, 3, 4, 6, 7, 9, 9, 9, 9, 10}
        sorted = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        
        Step 1:
            i = 5
            counting[i] => counting[5] => 9
            sorted[9 - 1] => sorted[8] = i => sorted[8] = 5 
            sorted = {0, 0, 0, 0, 0, 0, 0, 0, 5, 0}

        Step 2:
            i = 0
            counting[i] => counting[0] => 2
            sorted[2 - 1] => sorted[1] = i => sorted[1] = 0
            sorted = {0, 0, 0, 0, 0, 0, 0, 0, 5, 0}

        Step 3:
            i = 1
            counting[i] => counting[1] => 3
            sorted[3 - 1] => sorted[2] = i => sorted[2] = 1 
            sorted = {0, 0, 1, 0, 0, 0, 0, 0, 5, 0}
    */  
    for(auto& i : nums) {
        sorted[ counting[i]-1 ] = i;
        counting[i]--;
    }
    
    return sorted;
}

void print_vector(vector<int> vec) {

    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        if(i != vec.size()-1) {
            cout << vec[i] << ", ";
        }
        else {
            cout << vec[i];
        }
    }
    cout << "]" << endl;  
}

int main() {

    vector<int> nums{5, 0, 1, 2, 3, 5, 3, 0, 9, 4};

    vector<int> sorted = counting_sort(nums);

    cout << "Original vector = ";
    print_vector(nums);

    cout << "Sorted vector = ";
    print_vector(sorted);

    return 0;
}

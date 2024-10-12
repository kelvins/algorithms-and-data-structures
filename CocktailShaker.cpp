#include <iostream>
#include <vector>
using namespace std;

void cocktailShakerSort(vector<int>& arr) {
    bool exchanged = true;
    int start = 0;
    int end = arr.size() - 1;

    while (exchanged) {
        exchanged = false;

        // Traverse from left to right
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                exchanged = true;
            }
        }

        // If no elements were swapped, the array is already sorted
        if (!exchanged) {
            break;
        }

        exchanged = false;

        // Move the end point back by one
        --end;

        // Traverse from right to left
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                exchanged = true;
            }
        }

        // Move the start point forward by one
        ++start;
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8, 0, 2, 7};

    cocktailShakerSort(arr);

    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}

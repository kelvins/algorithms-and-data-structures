#include <iostream>
#include <vector>

/**
 * Function to find both the minimum and maximum elements in an array
 *
 * @param arr   The array to search in
 * @param left  The left index of the sub-array
 * @param right The right index of the sub-array
 * @param min   Reference to store the minimum element
 * @param max   Reference to store the maximum element
 */

void MinAndMax(const std::vector<int>& arr, int left, int right, int& min, int& max) {
    
    // if there is only one element in the subarray, it is both the minimum and maximum
    if (left == right) {
        min = max = arr[left];
        return;
    }

    // if there are two elements, compare and set min and max
    if (right - left == 1) {
        if (arr[left] < arr[right]) {
            min = arr[left];
            max = arr[right];
        }
        else {
            min = arr[right];
            max = arr[left];
        }
        return;
    }

    // calculate the middle index of the sub-array
    int mid = (left + right) / 2;
    int leftMin, leftMax, rightMin, rightMax;

    // recursively find min and max in the left and right sub-arrays
    MinAndMax(arr, left, mid, leftMin, leftMax);
    MinAndMax(arr, mid + 1, right, rightMin, rightMax);

    // update the minimum and maximum values
    min = std::min(leftMin, rightMin);
    max = std::max(leftMax, rightMax);
}

int main() {

    std::vector<int> arr = {10, 5, 20, 8, 15, 30, -12, 24};
    int min, max;

    MinAndMax(arr, 0, arr.size() - 1, min, max);

    std::cout << "Minimum element: " << min << std::endl;
    std::cout << "Maximum element: " << max << std::endl;

    return 0;
}

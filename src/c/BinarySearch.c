#include <stdio.h>

/**
 * Perform binary search to find the target element in a sorted array
 *
 * @param arr       The sorted array to search in
 * @param size      The number of elements in the array
 * @param target    The element to search for
 * @return          The index of the target element in the array, or -1 if not found
 */

int binarySearch(int arr[], int size, int target) {

    int left = 0;          // the leftmost index of the search range
    int right = size - 1;  // the rightmost index of the search range

    while (left <= right) {
        
        int mid = left + (right - left) / 2;  // calculate the middle index

        if (arr[mid] == target) {
            return mid;  // element found, return its index
        }

        if (arr[mid] < target) {
            left = mid + 1;  // adjust the left boundary to search the right sub-array
        }

        else {
            right = mid - 1; // adjust the right boundary to search the left sub-array
        }
    }

    return -1;  // element not found in the array
}

int main() {

    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    }

    else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}

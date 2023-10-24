#include <stdio.h>

/**
 * Function to find both the minimum and maximum elements in an array
 *
 * @param arr   The array to search in
 * @param left  The left index of the sub-array.
 * @param right The right index of the sub-array
 * @param min   Pointer to store the minimum element
 * @param max   Pointer to store the maximum element
 */

void MinAndMax(int arr[], int left, int right, int* min, int* max) {
    // if there is only one element in the sub-array, set it as both min and max
    if (left == right) {
        *min = *max = arr[left];
        return;
    }

    // if there are two elements in the sub-array, compare and set min and max
    if (right - left == 1) {
        if (arr[left] < arr[right]) {
            *min = arr[left];
            *max = arr[right];
        } else {
            *min = arr[right];
            *max = arr[left];
        }
        return;
    }

    // calculate the middle index of the sub-array
    int mid = (left + right) / 2;
    int leftMin, leftMax, rightMin, rightMax;

    // recursively find min and max in the left and right sub-arrays
    MinAndMax(arr, left, mid, &leftMin, &leftMax);
    MinAndMax(arr, mid + 1, right, &rightMin, &rightMax);

    // update the minimum and maximum values
    *min = (leftMin < rightMin) ? leftMin : rightMin;
    *max = (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    int arr[] = {10, 5, 20, 8, 15, 30, -12, 24};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int min, max;

    MinAndMax(arr, 0, arrSize - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}

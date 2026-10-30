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

void MinAndMax(int arr[], int left, int right, int *minimum, int *maximum) {
  // if there is only one element in the sub-array, set it as both min and max
  if (left == right) {
    *minimum = *maximum = arr[left];
    return;
  }

  // if there are two elements in the sub-array, compare and set min and max
  if (right - left == 1) {
    if (arr[left] < arr[right]) {
      *minimum = arr[left];
      *maximum = arr[right];
    } else {
      *minimum = arr[right];
      *maximum = arr[left];
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
  *minimum = (leftMin < rightMin) ? leftMin : rightMin;
  *maximum = (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
  int arr[] = {10, 5, 20, 8, 15, 30, -12, 24};
  int arrSize = sizeof(arr) / sizeof(arr[0]);

  int minimum, maximum;

  MinAndMax(arr, 0, arrSize - 1, &minimum, &maximum);

  printf("Minimum element: %d\n", minimum);
  printf("Maximum element: %d\n", maximum);

  return 0;
}

#include <iostream>
#include <vector>

/**
 * Merge two sub-arrays of arr[]
 * - First sub-array is arr[left..mid]
 * - Second sub-array is arr[mid+1..right]
 *
 * @param arr   The array to be sorted
 * @param left  The left index of the first sub-array
 * @param mid   The right index of the first sub-array
 * @param right The right index of the second sub-array
 */

void merge(std::vector<int> &arr, int left, int mid, int right) {

  int n1 = mid - left + 1; // size of the first sub-array.
  int n2 = right - mid;    // size of the second sub-array.

  // create temporary arrays to hold the data
  std::vector<int> leftSubarray(n1);
  std::vector<int> rightSubarray(n2);

  // copy data to temporary arrays leftSubarray[] and rightSubarray[]
  for (int i = 0; i < n1; i++) {
    leftSubarray[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    rightSubarray[j] = arr[mid + 1 + j];
  }

  // merge the two sub-arrays back into the original array arr[]
  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (leftSubarray[i] <= rightSubarray[j]) {
      arr[k] = leftSubarray[i];
      i++;
    } else {
      arr[k] = rightSubarray[j];
      j++;
    }
    k++;
  }

  // copy the remaining elements of leftSubarray[], if any
  while (i < n1) {
    arr[k] = leftSubarray[i];
    i++;
    k++;
  }

  // copy the remaining elements of rightSubarray[], if any
  while (j < n2) {
    arr[k] = rightSubarray[j];
    j++;
    k++;
  }
}

/**
 * Merge Sort algorithm
 *
 * @param arr   The array to be sorted
 * @param left  The left index of the sub-array to be sorted
 * @param right The right index of the sub-array to be sorted
 */

void mergeSort(std::vector<int> &arr, int left, int right) {
  if (left < right) {

    int mid = left + (right - left) / 2; // calculate the middle index

    // sort the first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // merge the sorted halves
    merge(arr, left, mid, right);
  }
}

int main() {

  std::vector<int> arr = {12, 11, 13, 5, 6, 7, 9, 4, 10, 9, 11, 1, 11};

  int arrSize = arr.size();

  std::cout << "Original array: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  mergeSort(arr, 0, arrSize - 1);

  std::cout << "Sorted array: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}

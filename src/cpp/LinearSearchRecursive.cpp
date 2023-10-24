#include <iostream>

using namespace std;

int linearSearchRecursive(int arr[], int n, int index, int target) {
  if (index >= n) {
    return -1;
  }
  
  if (arr[index] == target) {
    return index;
  }

  return linearSearchRecursive(arr, n, index + 1, target);
}

int main() {
  int n;
  cout << "Enter The size of array : ";
  cin >> n;
  int arr[n];
  cout << "Enter the element of array : " << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int target;
  cout << "Enter the element you need to search in the array : ";
  cin >> target;
  int answer = linearSearchRecursive(arr, n, 0, target);
  if (answer >= 0) {
    cout << "Target Element Found on index : " << answer << endl;
  } else {
    cout << "Target Element Not Found" << endl;
  }
}

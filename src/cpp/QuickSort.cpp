#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vector, int start, int end) {
  int pivot = vector[end];
  int index = start;

  for (int i = start; i < end; i++) {
    if (vector[i] < pivot) {
      int temp = vector[i];
      vector[i] = vector[index];
      vector[index] = temp;
      index++;
    }
  }

  if (pivot <= vector[index]) {
    vector[end] = vector[index];
    vector[index] = pivot;
  }

  return index;
}

void quickSort(vector<int> &vector, int start, int end) {
  if (start < end) {
    int pivot = partition(vector, start, end);
    quickSort(vector, start, pivot - 1);
    quickSort(vector, pivot + 1, end);
  }
}

void quickSort(vector<int> &vector) { quickSort(vector, 0, vector.size() - 1); }

void showVector(vector<int> vector) {
  for (uint32_t i = 0; i < vector.size(); ++i) {
    cout << vector[i] << ", ";
  }
  cout << "\n";
}

int main() {
  vector<int> vector;
  for (uint32_t i = 0; i < 10; ++i) {
    vector.push_back(rand() % 100);
  }
  showVector(vector);
  quickSort(vector);
  showVector(vector);
}

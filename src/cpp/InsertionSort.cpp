#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &vector) {

  for (uint32_t index = 1; index < vector.size(); index++) {
    int key = vector[index];
    int i = index - 1;

    while (i >= 0 && vector[i] > key) {
      vector[i + 1] = vector[i];
      i--;
    }

    vector[i + 1] = key;
  }
}

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
  insertionSort(vector);
  showVector(vector);
}

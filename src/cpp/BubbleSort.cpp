#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> vector) {
  for (uint32_t end = vector.size() - 1; end > 0; --end) {
    for (uint32_t index = 0; index < end; ++index) {
      if (vector[index] > vector[index + 1]) {
        int temp = vector[index];
        vector[index] = vector[index + 1];
        vector[index + 1] = temp;
      }
    }
  }
  return vector;
}

void showVector(vector<int> vector) {
  for (uint32_t i = 0; i < vector.size(); ++i) {
    if (i + 1 == vector.size())
      cout << vector[i];
    else
      cout << vector[i] << ", ";
  }
  cout << "\n";
}

int main() {
  vector<int> vector;
  for (uint32_t i = 0; i < 10; ++i) {
    vector.push_back(rand() % 100);
  }
  cout << "Initial Vector: ";
  showVector(vector);
  vector = bubbleSort(vector);
  cout << "Sorted Vector: ";
  showVector(vector);
}

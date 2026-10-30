#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void combSort(std::vector<int> &values) {
  std::size_t gap = values.size();
  constexpr double shrinkFactor = 1.3;
  bool swapped = true;

  while (gap > 1 || swapped) {
    gap = static_cast<std::size_t>(gap / shrinkFactor);
    if (gap < 1) {
      gap = 1;
    }

    swapped = false;
    for (std::size_t i = 0; i + gap < values.size(); ++i) {
      if (values[i] > values[i + gap]) {
        std::swap(values[i], values[i + gap]);
        swapped = true;
      }
    }
  }
}

void printVector(const std::string &label, const std::vector<int> &values) {
  std::cout << label << ": ";
  for (std::size_t i = 0; i < values.size(); ++i) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << values[i];
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> values1 = {3, 15, 4, 3, 2, 4, 14, 7, 10, 3, 20, 8, 4, 9, 5};
  printVector("Initial vector 1", values1);
  combSort(values1);
  printVector("Sorted vector 1", values1);

  std::vector<int> values2 = {10, 164, 20, 50, 70, 90, 1, 90, 14, 530, 439};
  printVector("Initial vector 2", values2);
  combSort(values2);
  printVector("Sorted vector 2", values2);
}

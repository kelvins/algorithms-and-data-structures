#include <iostream>
#include <unordered_map>
#include <vector>

/*!
 * \brief Determine whether in the list of retrieved numbers there is a
 combination of two numbers that resulted in the target sum.
 *  \return Two indexes of the list whose sum of elements results in the
 target value
 */
std::vector<int> twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> mapSum; // val, vect<idx>

  for (int i = 0; i < nums.size(); i++) {
    int compTarget = target - nums[i];

    if (mapSum.count(compTarget)) {
      return {i, mapSum[compTarget]};
    } else {
      mapSum.insert({nums[i], i});
    }
  }

  return {};
}

int main() {
  std::vector<int> values{9, 1, 2, 5, 7, 11, 15};
  int target = 9;

  auto sumIdxFor = twoSum(values, target);
  if (sumIdxFor.empty()) {
    std::cout << "no existent values with two sum: " << target << " in array"
              << std::endl;
  } else {
    std::cout << "Two sum for target: " << target << " in array is "
              << values[sumIdxFor[0]] << " and " << values[sumIdxFor[1]]
              << std::endl;
  }

  return 0;
}

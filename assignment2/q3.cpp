#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

std::vector<int> inputSortedArray(int size) {
  std::vector<int> output;
  output.reserve(size);
  for (int i = 0; i < size; i++) output.push_back(0);
  int prev_item = INT_MIN;
  int x;
  for (int i = 0; i < size; i++) {
    std::cout << "Enter Item " << i + 1 << ": ";
    std::cin >> x;
    if (x < prev_item) {
      std::cout << "Please enter the array in a sorted manner\n";
      i--;
      continue;
    }
    output[i] = x;
    prev_item = x;
  }
  return output;
}

int sum(const std::vector<int>& arr) {
  int sum = 0;
  for (const int& item : arr) {
    sum += item;
  }
  return sum;
}

int diff(std::vector<int>& sorted_array1, std::vector<int>& sorted_array2) {
  assert(sorted_array1.size() == sorted_array2.size() + 1);

  for (int i = 0; i < sorted_array2.size(); i++) {
    int item1 = sorted_array1[i];
    int item2 = sorted_array2[i];
    if (item1 == item2) continue;

    return item1;
  }
  return sorted_array1[sorted_array1.size() - 1];
}

int main() {
  int size;
  std::cout << "Enter required array size: ";
  std::cin >> size;

  auto original = inputSortedArray(size);
  auto new_array = inputSortedArray(size - 1);

  int missing_item = diff(original, new_array);
  std::cout << "The missing number is " << missing_item << "\n";
}

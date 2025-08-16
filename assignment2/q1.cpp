#include <climits>
#include <iostream>
#include <optional>
#include <vector>

std::optional<int> binarySearch(const std::vector<int>& arr, const int item_to_find) {
  int left = 0;
  int right = arr.size();

  while (left <= right) {
    int mid = (left + right) / 2;
    int item = arr[mid];
    if (item == item_to_find) return mid;

    if (item > item_to_find) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return std::nullopt;
}

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

int main() {
  int size;
  std::cout << "Enter the size of array: ";
  std::cin >> size;
  auto response = inputSortedArray(size);

  int item_to_find;
  std::cout << "Enter item to find: ";
  std::cin >> item_to_find;

  std::optional<int> index = binarySearch(response, item_to_find);
  if (index.has_value()) {
    std::cout << "Item found at index: " << index.value() << "\n";
  } else {
    std::cout << "Item not found\n";
  }
  return 0;
}

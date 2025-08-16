#include <climits>
#include <iostream>
#include <vector>

std::vector<int> inputArray(int size) {
  std::vector<int> output;
  output.reserve(size);

  int x;
  for (int i = 0; i < size; i++) {
    std::cout << "Enter Item " << i + 1 << ": ";
    std::cin >> x;
    output.push_back(x);
  }

  return output;
};

int sum(const std::vector<int>& arr) {
  int sum = 0;
  for (const int& item : arr) {
    sum += item;
  }
  return sum;
}

int main() {
  int size;
  std::cout << "Enter required array size: ";
  std::cin >> size;

  auto original = inputArray(size);
  int original_sum = sum(original);
  auto new_array = inputArray(size - 1);
  int new_array_sum = sum(original);

  std::cout << "The missing number is " << new_array_sum - original_sum << "\n";
}

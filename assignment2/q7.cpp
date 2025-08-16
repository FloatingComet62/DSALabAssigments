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

int main() {
  int size;
  std::cout << "Size: ";
  std::cin >> size;
  auto arr = inputArray(size);

  int inversion_count = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] <= arr[j]) continue;
      inversion_count++;
    }
  }
  std::cout << "Counted " << inversion_count << " inversions\n";
}

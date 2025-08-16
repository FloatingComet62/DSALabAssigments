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
  std::cout << "Enter size of required tri-diagonal matrix: ";
  std::cin >> size;
  if (size < 3) {
    std::cout << "Not a tri-diagonal matrix";
    return 1;
  }
  auto matrix = inputArray((size - 2) * 3 + 4);

  int k = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i + 2 <= j || j <= i - 2) {
        std::cout << "0 ";
        continue;
      }
      std::cout << matrix[k++] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}

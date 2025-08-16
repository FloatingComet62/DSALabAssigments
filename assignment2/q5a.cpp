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
  std::cout << "Enter size of required diagonal matrix: ";
  std::cin >> size;
  auto matrix = inputArray(size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i != j) {
        std::cout << "0 ";
        continue;
      }
      std::cout << matrix[i] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}

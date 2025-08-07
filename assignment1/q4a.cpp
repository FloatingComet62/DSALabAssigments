#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

int EXIT_INT = 0;
std::vector<int> inputArray() {
  std::vector<int> output;
  std::cout << "Use " << EXIT_INT << " to exit\n";
  for (int i = 1;;i++) {
    std::cout << "Enter value " << i << " > ";
    int num;
    std::cin >> num;
    if (num == EXIT_INT) break;
    output.push_back(num);
  }
  return output;
}

void reverse(std::vector<int>& arr) {
  int swap_till = std::floor(arr.size() / 2);
  auto iter = arr.begin();
  auto iter_back = arr.rbegin();
  for (int i = 0; i < swap_till; i++) {
    std::swap(*iter, *iter_back);
    iter++;
    iter_back++;
  }
}

int main() {
  std::vector<int> arr = inputArray();
  reverse(arr);
  for (auto it = arr.begin(); it != arr.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

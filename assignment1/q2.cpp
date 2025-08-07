// #include <algorithm>
#include <iostream>
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

bool in_vec(int target, const std::vector<int>& arr) {
  for (const int& item : arr) {
    if (item == target) return true;
  }
  return false;
}

void dedupe(std::vector<int>& arr) {
  // arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
  std::vector<int> unduped;
  unduped.reserve(arr.size());
  for (auto iter = arr.begin(); iter != arr.end(); iter++) {
    if (in_vec(*iter, unduped)) continue;
    unduped.push_back(*iter);
  }
  arr = unduped;
}

int main() {
  auto arr = inputArray();
  dedupe(arr);
  for (auto it = arr.begin(); it != arr.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

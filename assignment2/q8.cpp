#include <unordered_set>
#include <iostream>

int main() {
  int size;
  std::cout << "Size: ";
  std::cin >> size;

  std::unordered_set<int> set;
  int x;
  for (int i = 0; i < size; i++) {
    std::cout << "Enter Item " << i + 1 << ": ";
    std::cin >> x;
    set.insert(x);
  }

  int sum = 0;
  for (const int& item : set) {
    sum += item;
  }
  std::cout << "Distinct item sum: " << sum << "\n";
}

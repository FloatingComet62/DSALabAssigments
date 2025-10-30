#include <vector>
#include <iostream>
#include "stack.hpp"

int main() {
  std::vector<int> aa = {1, 4, 2, 6, 8, 3, 5, 9, 4, 6, 7, 8};
  std::vector<int> bb;
  Stack ss;

  while (true) {
    int res;
    std::cin >> res;
    if (res == 0) {
      ss.push(aa[0]);
      aa.erase(aa.begin());
    } else {
      int top = ss.pop();
      bb.push_back(top);
    }
    std::cout << "aa:\n";
    for (int i = 0; i < aa.size(); i++) {
      std::cout << aa[i] << " ";
    }
    std::cout << "\nbb:\n";
    for (int i = 0; i < bb.size(); i++) {
      std::cout << bb[i] << " ";
    }
    std::cout << std::endl;
  }
}

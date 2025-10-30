#include <iostream>

int main() {
  int n; std::cout << "n: "; std::cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 31; j >= 0; j--) {
      std::cout << ((i >> j) & 0b1);
    }
    std::cout << "\n";
  }
}

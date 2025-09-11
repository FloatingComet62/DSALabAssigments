#include <algorithm>
#include <iostream>
#include <string> 

std::string inputStr(std::string prompt) {
  std::cout << prompt;
  std::string output;
  std::cin >> output;
  return output;
}

void sortStr(std::string& str) {
  int n = str.size();
  bool swappingOccurred;
  for (int i = 0; i < n; i++) {
    swappingOccurred = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (str[j] <= str[j + 1]) continue;
      swappingOccurred = true;
      str[j    ] ^= str[j + 1];
      str[j + 1] ^= str[j    ];
      str[j    ] ^= str[j + 1];
    }
    if (!swappingOccurred) return;
  }
}

int main() {
  auto str = inputStr("Enter string: ");
  sortStr(str);

  std::cout << "Sorted string: " << str << "\n";
}

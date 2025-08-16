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
  std::sort(str.begin(), str.end());
}

int main() {
  auto str = inputStr("Enter string: ");
  sortStr(str);

  std::cout << "Sorted string: " << str << "\n";
}

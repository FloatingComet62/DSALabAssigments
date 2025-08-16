#include <iostream>
#include <string> 

std::string inputStr(std::string prompt) {
  std::cout << prompt;
  std::string output;
  std::cin >> output;
  return output;
}

std::string reversedStr(std::string& str) {
  std::string output;
  output.reserve(str.size());

  for (int i = str.size() - 1; i >= 0; i--) {
    output.push_back(str[i]);
  }

  return output;
}

int main() {
  auto str = inputStr("Enter string: ");
  auto reversed = reversedStr(str);

  std::cout << "Reversed input string: " << reversed << "\n";
}

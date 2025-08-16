#include <iostream>
#include <string> 

std::string inputStr(std::string prompt) {
  std::cout << prompt;
  std::string output;
  std::cin >> output;
  return output;
}

std::string loweredStr(const std::string& str) {
  std::string output;
  output.reserve(str.size());

  for (int i = 0; i < str.size(); i++) {
    int c = str[i];
    if (c >= 'A' && c <= 'Z') {
      output.push_back(c - 'A' + 'a');
      continue;
    }
    output.push_back(c);
  }

  return output;
}

int main() {
  auto str = inputStr("Enter string: ");
  auto lowerStr = loweredStr(str);

  std::cout << "Lowered string: " << lowerStr << "\n";
}

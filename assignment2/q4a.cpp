#include <iostream>
#include <string> 

std::string inputStr(std::string prompt) {
  std::cout << prompt;
  std::string output;
  std::cin >> output;
  return output;
}

int main() {
  auto a = inputStr("Enter string A: ");
  auto b = inputStr("Enter string B: ");

  std::string output;
  for (int i = 0; i < a.size(); i++) {
    output.push_back(a[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    output.push_back(b[i]);
  }

  std::cout << "Appended string: " << a << "\n";
}

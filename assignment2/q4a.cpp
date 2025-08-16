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

  a.append(a);

  std::cout << "Appended string: " << a << "\n";
}

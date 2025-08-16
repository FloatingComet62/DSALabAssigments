#include <iostream>
#include <string> 

std::string inputStr(std::string prompt) {
  std::cout << prompt;
  std::string output;
  std::cin >> output;
  return output;
}

std::string vowelLessStr(std::string& str) {
  std::string output;
  output.reserve(str.size());

  for (int i = 0; i < str.size(); i++) {
    int c = str[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
    output.push_back(c);
  }

  return output;
}

int main() {
  auto str = inputStr("Enter string: ");
  auto noVowelStr = vowelLessStr(str);

  std::cout << "Vowel less string: " << noVowelStr << "\n";
}

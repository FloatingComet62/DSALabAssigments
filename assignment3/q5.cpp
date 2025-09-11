#include "stack.hpp"
#include <string>

[[noreturn]] inline void unreachable() {
    // Uses compiler specific extensions if possible.
    // Even if no extension is used, undefined behavior is still raised by
    // an empty function body and the noreturn attribute.
#if defined(_MSC_VER) && !defined(__clang__) // MSVC
    __assume(false);
#else // GCC, Clang
    __builtin_unreachable();
#endif
}

bool isOperator(char item) {
  return item == '+' || item == '-' || item == '*' || item == '/';
}

int calc(int a, int b, char op) {
  switch (op) {
    case '+':
      return a + b;
      break;
    case '-':
      return a - b;
      break;
    case '*':
      return a * b;
      break;
    case '/':
      return a / b;
      break;
    default: unreachable();
  }
}

int main() {
  std::string expr;
  std::cout << "> ";
  std::getline(std::cin, expr);

  Stack stack;
  for (const auto& item : expr) {
    if (!isOperator(item)) {
      stack.push(item - '0');
      continue;
    }
    int operandB = stack.pop();
    int operandA = stack.pop();
    int result = calc(operandA, operandB, item);
    stack.push(result);
  }
  std::cout << stack.pop() << "\n";
}

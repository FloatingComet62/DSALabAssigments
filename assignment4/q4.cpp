#include "queue.hpp"
#include <iostream>
#include <string>

int main() {
  std::string s;
  std::getline(std::cin, s);

  Queue q;
  for (int i = 0; i < s.size(); i++) {
    int unique = true;
    for (int j = q.top; j != q.bottom; j = (j + 1) % QUEUE_CAPACITY) {
      if (s[i] == q.data[j]) {
        unique = false;
        break;
      }
    }
    if (!unique) {
      continue;
    }
    q.enqueue(s[i]);
  }

  std::string output;
  while (!q.isEmpty()) output += (char)q.dequeue();
  std::cout << output << "\n";
  return 0;
}

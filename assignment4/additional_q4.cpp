#include <iostream>
#include <vector>
#include <queue>

int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
  std::queue<int> q;
  for (int x : students) q.push(x);
  int i = 0, rotations = 0, n = students.size();
  while (!q.empty() && rotations < q.size()) {
    if (q.front() == sandwiches[i]) {
      q.pop();
      i++;
      rotations = 0;
      continue;
    }
    q.push(q.front());
    q.pop();
    rotations++;
  }
  return q.size();
}

int main() {
  std::vector<int> students = { 1, 1, 0, 0 };
  std::vector<int> sandwiches = { 0, 1, 0, 1 };
  std::cout << countStudents(students, sandwiches);
  return 0;
}

#include <iostream>
#include <vector>

void duplicateTwos(std::vector<int>& arr) {
  int n = arr.size();
  int countTwos = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 2) countTwos++;
  }

  int i = n - 1;
  int j = n + countTwos - 1;

  while (i != j) {
    if (j < n) arr[j] = arr[i];
    if (arr[i] == 2) {
      j--;
      if (j < n) arr[j] = 2;
    }
    i--;
    j--;
  }
}

int main() {
  std::vector<int> arr = { 1, 2, 3, 2, 4, 5 };
  duplicateTwos(arr);
  for (int x : arr) std::cout << x << " ";
}

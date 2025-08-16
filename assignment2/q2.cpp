#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j + 1] >= arr[j]) { continue; }
      arr[j + 1] ^= arr[j];
      arr[j]     ^= arr[j + 1];
      arr[j + 1] ^= arr[j];
    }
  }
}

int main() {
  std::vector array = {64, 34, 25, 12, 22, 11, 90};
  bubbleSort(array);

  std::cout << "Sorted output: \n";
  for (int i = 0; i < array.size(); i++) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
  return 0;
}

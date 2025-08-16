#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  bool swappingOccured;
  for (int i = 0; i < n; i++) {
    swappingOccured = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j + 1] >= arr[j]) { continue; }
      arr[j + 1] ^= arr[j];
      arr[j]     ^= arr[j + 1];
      arr[j + 1] ^= arr[j];
      swappingOccured = true;
    }
    if (!swappingOccured) return;
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

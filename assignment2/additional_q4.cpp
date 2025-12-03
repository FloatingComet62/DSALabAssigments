#include <iostream>

int main() {
  int n;
  std::cout << "Enter n: "; std::cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cout << "arr[" << i << "]: "; std::cin >> arr[i];
  }

  int low = 0, mid = 0, high = n - 1;
  while (mid <= high) {
    if (arr[mid] == 0) {
      std::swap(arr[low], arr[mid]);
      low++;
      mid++;
    }
    else if (arr[mid] == 1) {
      mid++;
    }
    else {
      std::swap(arr[mid], arr[high]);
      high--;
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}

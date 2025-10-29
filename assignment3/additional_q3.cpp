#include <cassert>

void nextGreaterElement(int* arr, int* output, int n) {
  for (int i = 0; i < n; i++) {
    output[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] <= arr[i]) continue;
      output[i] = arr[j];
      break;
    }
  }
}

int main() {
  int arr[5] = {0, 2, 1, 4, 4};
  int output[5];
  nextGreaterElement(arr, output, 5);
  assert(output[0] == 2);
  assert(output[1] == 4);
  assert(output[2] == 4);
  assert(output[3] == -1);
  assert(output[4] == -1);
}

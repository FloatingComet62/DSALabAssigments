#include <cassert>

void dailyTemperature(int* arr, int* output, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (arr[j] <= arr[i]) continue;
      output[i] = j - i;
      break;
    }
  }
}

int main() {
  int arr[5] = {0, 1, 2, 1, 4};
  int output[5];
  dailyTemperature(arr, output, 5);
  assert(output[0] == 1);
  assert(output[1] == 1);
  assert(output[2] == 2);
  assert(output[3] == 1);
  assert(output[4] == 0);
}

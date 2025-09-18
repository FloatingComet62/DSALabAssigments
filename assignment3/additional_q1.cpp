#include <cassert>
#include <cstdlib>
int* prevSmaller(int* A, int n1, int *len1) {
  *len1 = n1;

  int* output = (int*)malloc(sizeof(*output) * 5);
  for (int i = 0; i < n1; i++) {
    output[i] = -1;
    for (int j = i - 1; j >= 0; j--) {
      if (A[j] < A[i]) {
        output[i] = A[j];
        break;
      }
    }
  }
  return output;
}

int main() {
  int arr[5] = {4, 5, 2, 10, 8};
  int len;
  int* output = prevSmaller(&arr[0], 5, &len);

  assert(len == 5);
  assert(output[0] == -1);
  assert(output[1] == 4);
  assert(output[2] == -1);
  assert(output[3] == 2);
  assert(output[4] == 2);
}

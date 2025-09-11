#include <cstdlib>
#include <iostream>

typedef struct {
  int* data;
  int len;
} vec;

vec init_da(int capacity) {
  int* da = (int*)malloc(capacity * sizeof(int));
  return { da, 0 };
}
void da_append(vec& self, int item) {
  self.data[self.len] = item;
  self.len++;
}
bool da_contains(vec& self, int target_item) {
  for (int i = 0; i < self.len; i++) {
    if (self.data[i] == target_item) return true;
  }
  return false;
}

void redirect(int* dir_i_ptr, int* dir_j_ptr) {
  int dir_i = *dir_i_ptr;
  int dir_j = *dir_j_ptr;

  if (dir_i == 0 && dir_j == 1) {
    *dir_i_ptr = 1;
    *dir_j_ptr = 0;
    return;
  }
  if (dir_i == 1 && dir_j == 0) {
    *dir_i_ptr = 0;
    *dir_j_ptr = -1;
    return;
  }
  if (dir_i == 0 && dir_j == -1) {
    *dir_i_ptr = -1;
    *dir_j_ptr = 0;
    return;
  }
  *dir_i_ptr = 0;
  *dir_j_ptr = 1;
  return;
}

int* spiralOrder(const int* A, int n11, int n12, int *len1) {
  int len = n11 * n12;
  vec output = init_da(len);
  vec visited = init_da(len);

  int dir_i = 0, dir_j = 1;
  int i = 0, j = 0;
  int non_stop_redirect = 0;

  while (true) {
    if (non_stop_redirect > 3) break;
    if (da_contains(visited, i * n11 + j)) {
      non_stop_redirect++;
      redirect(&dir_i, &dir_j);
      i += dir_i;
      j += dir_j;
      continue;
    }
    non_stop_redirect = 0;
    da_append(output, A[i * n11 + j]);
    da_append(visited, i * n11 + j);

    i += dir_i;
    j += dir_j;
    if (i >= n12 || j >= n11 || i < 0 || j < 0) {
      i -= dir_i;
      j -= dir_j;
      redirect(&dir_i, &dir_j);
      i += dir_i;
      j += dir_j;
    }
  }

  *len1 = output.len;
  return output.data;
}

int main() {
  int A[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  int len;
  int* mem = spiralOrder(&A[0][0], 3, 3, &len);
  for (int i = 0; i < len; i++) {
    std::cout << mem[i] << " ";
  }
  std::cout << std::endl;
}

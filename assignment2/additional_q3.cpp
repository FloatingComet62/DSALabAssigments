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

int* generateMatrix(int A, int *len1, int *len2) {
  int* matrix = (int*)malloc(A * A * sizeof(int));
  vec visited = init_da(A * A);

  int dir_i = 0, dir_j = 1;
  int i = 0, j = 0;
  int non_stop_redirect = 0;

  int k = 0;
  while (true) {
    if (non_stop_redirect > 5) break;
    int ij = i * A + j;
    if (da_contains(visited, ij)) {
      i -= dir_i;
      j -= dir_j;
      non_stop_redirect++;
      redirect(&dir_i, &dir_j);
      i += dir_i;
      j += dir_j;
      continue;
    }
    non_stop_redirect = 0;
    matrix[ij] = k++;
    da_append(visited, ij);

    i += dir_i;
    j += dir_j;
    if (i >= A || j >= A || i < 0 || j < 0) {
      i -= dir_i;
      j -= dir_j;
      redirect(&dir_i, &dir_j);
      i += dir_i;
      j += dir_j;
    }
  }

  *len1 = A;
  *len2 = A;
  return matrix;
}

int main() {
  int len1, len2, A;
  std::cout << "Size: ";
  std::cin >> A;
  int* mem = generateMatrix(A, &len1, &len2);
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      std::cout << mem[i * len2 + j] << " ";
    }
    std::cout << "\n";
  }
}

//  0  1  2  3  4
//  5  6  7  8  9
// 10 11 12 13 14
// 15 16 17 18 19
// 20 21 22 23 24

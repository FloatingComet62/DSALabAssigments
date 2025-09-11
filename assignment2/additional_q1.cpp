#include <iostream>

bool saddlePoint(int x, int y, int matrix[5][5]) {
  for (int i = 0; i < 5; i++) {
    if (matrix[i][y] > matrix[x][y]) return false;
  }
  for (int i = 0; i < 5; i++) {
    if (matrix[x][i] < matrix[x][y]) return false;
  }
  return true;
}

int main() {
  int matrix[5][5] = {
    {5, 4, 3, 4, 5},
    {6, 5, 4, 5, 6},
    {7, 6, 5, 6, 7},
    {6, 5, 4, 5, 6},
    {5, 4, 3, 4, 5},
  };
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (!saddlePoint(i, j, matrix)) continue;
      std::cout << "At (" << i <<  ", " << j << ") " << "is the saddle point of the matrix\n";
    }
  }
}

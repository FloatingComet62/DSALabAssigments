#include "q6.hpp"

int main() {
  int row, column;
  std::cout << "Row size: ";
  std::cin >> row;
  std::cout << "Column size: ";
  std::cin >> column;

  SparseMatrix matrixA;
  matrixA.input();

  std::cout << "Matrix A:\n";
  matrixA.print();

  SparseMatrix matrixB;
  matrixB.input();

  std::cout << "Matrix B:\n";
  matrixB.print();

  SparseMatrix sum(matrixA);

  // for (auto& matrixBItem : matrixB.items) {
  for (int i = 0; i < matrixB.items.items_length; i++) {
    Item matrixBItem = matrixB.items.data[i];
    bool found = false;
    for (int j = 0; j < sum.items.items_length; j++) {
      Item sumItem = sum.items.data[j];
      if (matrixBItem.equate(sumItem)) {
        sumItem.data += matrixBItem.data;
        found = true;
      }
    }
    if (found) {
      continue;
    }
    sum.items.append(matrixBItem);
  }

  std::cout << "Sum:\n";
  sum.print();
}

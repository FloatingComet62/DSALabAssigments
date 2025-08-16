#include "q6.hpp"

int main() {
  int row, column;
  std::cout << "Row size: ";
  std::cin >> row;
  std::cout << "Column size: ";
  std::cin >> column;

  SparseMatrix matrixA(row, column);
  matrixA.input();

  std::cout << "Matrix A:\n";
  matrixA.print();

  SparseMatrix matrixB(column, row);
  matrixB.input();

  std::cout << "Matrix B:\n";
  matrixB.print();

  SparseMatrix product(row, row);

  for (int i = 0; i < row; i++) {
    for (int j = 0;j < row; j++) {
      int item = 0;
      for (int k = 0; k < column; k++) {
        item += matrixA.getItem(i, k, 0) * matrixB.getItem(k, j, 0);
      }
      if (item == 0) continue;
      product.addItem(i, j, item);
    }
  }

  std::cout << "Product:\n";
  product.print();
}

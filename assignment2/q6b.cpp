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

  SparseMatrix matrixB(row, column);
  matrixB.input();

  std::cout << "Matrix B:\n";
  matrixB.print();

  SparseMatrix sum(matrixA);

  for (auto& matrixBItem : matrixB.items) {
    bool found = false;
    for (auto& sumItem : sum.items) {
      if (matrixBItem.equate(sumItem)) {
        sumItem.data += matrixBItem.data;
        found = true;
      }
    }
    if (found) {
      continue;
    }
    sum.items.push_back(matrixBItem);
  }

  std::cout << "Sum:\n";
  sum.print();
}

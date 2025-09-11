#include "q6.hpp"

int main() {
  int row, column;
  std::cout << "Row size: ";
  std::cin >> row;
  std::cout << "Column size: ";
  std::cin >> column;

  SparseMatrix original;
  original.input();

  std::cout << "Original matrix:\n";
  original.print();

  SparseMatrix transposed;
  for (int i = 0) {
    transposed.items.append(item.transpose());
  }

  std::cout << "Transposed matrix:\n";
  transposed.print();
}

#include "q6.hpp"

int main() {
  int row, column;
  std::cout << "Row size: ";
  std::cin >> row;
  std::cout << "Column size: ";
  std::cin >> column;

  SparseMatrix original(row, column);
  original.input();

  std::cout << "Original matrix:\n";
  original.print();

  SparseMatrix transposed(column, row);
  for (const auto& item : original.items) {
    transposed.items.push_back(item.transpose());
  }

  std::cout << "Transposed matrix:\n";
  transposed.print();
}

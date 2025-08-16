#include <iostream>
#include <vector>

class Item {
public:
  int rowIdx;
  int columnIdx;
  int data;
  Item(int rowIdx, int columnIdx, int data) {
    this->rowIdx = rowIdx;
    this->columnIdx = columnIdx;
    this->data = data;
  }
  bool equate(Item& item2) {
    return this->rowIdx == item2.rowIdx && this->columnIdx == item2.columnIdx;
  }
  bool equate(int rowIdx, int columnIdx) {
    return this->rowIdx == rowIdx && this->columnIdx == columnIdx;
  }
  int get() {
    return data;
  }

  Item transpose() const {
    return Item(this->columnIdx, this->rowIdx, this->data);
  }
};
class SparseMatrix {
public:
  std::vector<Item> items;
  int numRows;
  int numColumns;
  SparseMatrix(int row_count, int column_count) {
    this->numRows = row_count;
    this->numColumns = column_count;
  }
  bool addItem(int rowIdx, int columnIdx, int data) {
    if (rowIdx >= this->numRows) {
      std::cout << "Invalid row";
      return false;
    }
    if (rowIdx >= this->numColumns) {
      std::cout << "Invalid row";
      return false;
    }
    this->items.push_back(Item(rowIdx, columnIdx, data));
    return true;
  }
  int getItem(int rowIdx, int columnIdx, int defaultValue) {
    for (auto item : this->items) {
      if (!item.equate(rowIdx, columnIdx)) continue;
      return item.data;
    }
    return defaultValue;
  }

  int EXIT_INT = 0;
  void input() {
      std::cout << "Item insertion menu: \n";
      while (true) {
        int rowIdx, columnIdx, data;
        std::cout << "Enter row: "; std::cin >> rowIdx;
        std::cout << "Enter column: "; std::cin >> columnIdx;
        std::cout << "Enter data: "; std::cin >> data;
        if (data == EXIT_INT) break;
        if (!this->addItem(rowIdx, columnIdx, data)) {
          std::cout << "Row & column out of range, failed to insert\n";
        }
      }
  }

  void print() {
    for (int i = 0; i < this->numRows; i++) {
      for (int j = 0; j < this->numColumns; j++) {
        std::cout << this->getItem(i, j, 0) << " ";
      }
      std::cout << "\n";
    }
  }
};

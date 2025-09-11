#include <cstdlib>
#include <iostream>

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

class Items {
  int items_capacity;
public:
  int items_length;
  Item* data;
  Items() {
    this->data = (Item*)malloc(5 * sizeof(*this->data));
    this->items_length = 0;
    this->items_capacity = 5;
  }
  void append(Item new_item) {
    if (this->items_capacity < this->items_length + 1) {
      this->reserve(this->items_capacity + 10);
    }
    this->data[this->items_length++] = new_item;
  }
  void reserve(int new_capacity) {
    this->data = (Item*)realloc(this->data, new_capacity);
    this->items_capacity = new_capacity;
  }
};

class SparseMatrix {
public:
  Items items;

  SparseMatrix() {
    items = Items();
    items.data[0] = Item(0, 0, 0);
  }
  void addItem(int rowIdx, int columnIdx, int data) {
    if (rowIdx > this->items.data[0].rowIdx) {
      this->items.data[0].rowIdx = rowIdx;
    }
    if (columnIdx > this->items.data[0].columnIdx) {
      this->items.data[0].columnIdx = columnIdx;
    }
    this->items.data[0].data++;
    items.append(Item(rowIdx, columnIdx, data));
  }
  int getItem(int rowIdx, int columnIdx, int defaultValue) { 
    return defaultValue;
  }

  int EXIT_INT = 0;
  void input() {
    std::cout << "Enter number of rows: ";
    std::cin >> this->items.data[0].rowIdx;
    std::cout << "Enter number of column: ";
    std::cin >> this->items.data[0].columnIdx;

    for (int i = 0; i < this->items.data[0].rowIdx; i++) {
      for (int j = 0; j < this->items.data[0].columnIdx; j++) {
        std::cout << "Enter item (" << i << ", " << j << "): ";
        int value;
        std::cin >> value;
        if (value == 0) continue;
        this->addItem(i, j, value);
      }
    }
  }

  void print() {
    for (int i = 0; i < this->items.data[0].rowIdx; i++) {
      for (int j = 0; j < this->items.data[0].columnIdx; j++) {
        int value = this->getItem(i, j, 0);
        std::cout << value << " ";
      }
      std::cout << "\n";
    }
  }
};

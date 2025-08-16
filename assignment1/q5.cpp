#include <iostream>
#include <vector>

class Matrix {
  public:
    int column_count;
    int row_count;
    std::vector<int> data;
    Matrix(int row_count, int column_count) {
      this->row_count = row_count;
      this->column_count = column_count;
      data.reserve(column_count * row_count);
      for (int i = 0; i < column_count * row_count; i++) {
        data.push_back(0);
      }
    }
    void set(int row_idx, int col_idx, int value) {
      data[row_idx * this->column_count + col_idx] = value;
    }
    int get(int row_idx, int col_idx) {
      return data[row_idx * this->column_count + col_idx];
    }
    void print() {
      for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
          std::cout << get(i, j) << "\t";
        }
        std::cout << "\n";
      }
    }
};

Matrix inputMatrix(int a, int b) {
  Matrix output(a, b);
  std::cout << "Inputting a matrix of dimensions " << a << "x" << b << "\n";
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      std::cout << "Row(" << i << "), Column(" << j << "): ";
      int num;
      std::cin >> num;
      output.set(i, j, num);
    }
  }
  return output;
}

int main() {
  int rows, columns;
  std::cout << "Number of rows: ";
  std::cin >> rows;
  std::cout << "Number of columns: ";
  std::cin >> columns;
  Matrix matrix = inputMatrix(rows, columns);
  for (int i = 0; i < matrix.row_count; i++) {
    int row_sum = 0;
    for (int j = 0; j < matrix.column_count; j++) {
      row_sum += matrix.get(i, j);
    }
    std::cout << "Row(" << i << ") Sum: " << row_sum << "\n";
  }

  for (int i = 0; i < matrix.column_count; i++) {
    int column_sum = 0;
    for (int j = 0; j < matrix.row_count; j++) {
      column_sum += matrix.get(j, i);
    }
    std::cout << "Column(" << i << ") Sum: " << column_sum << "\n";
  }
}

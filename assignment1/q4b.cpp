#include <iostream>
#include <vector>
#include <optional>

class Matrix {
  public:
    int column_count;
    int row_count;
    std::vector<int> data;
    Matrix(int column_count, int row_count) {
      this->column_count = column_count;
      this->row_count = row_count;
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

std::optional<Matrix> multiply(Matrix a, Matrix b) {
  if (a.column_count != b.row_count) {
    return std::nullopt;
  }
  Matrix output(a.row_count, b.column_count);
  for (int i = 0; i < a.row_count; i++) {
    for (int j = 0; j < b.column_count; j++) {
      int num = 0;
      for (int k = 0; k < a.column_count; k++) {
        num += a.get(i, k) * b.get(k, j);
      }
      output.set(i, j, num);
    }
  }
  return output;
}

int main() {
  int rows, columns, columns2;
  std::cout << "Number of rows for matrix 1: ";
  std::cin >> rows;
  std::cout << "Number of columns for matrix 1: ";
  std::cin >> columns;
  Matrix matrixA = inputMatrix(rows, columns);
  std::cout << "Matrix A\n";
  matrixA.print();
  std::cout << "Number of columns for matrix 2: ";
  std::cin >> columns;
  Matrix matrixB = inputMatrix(columns, columns2);
  std::cout << "Matrix B\n";
  matrixB.print();
  auto result = multiply(matrixA, matrixB);
  if (result.has_value()) {
    std::cout << "A x B\n";
    result.value().print();
  } else {
    std::cout << "Can't multiply this shit";
  }
}

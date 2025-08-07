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
    Matrix transpose() {
      Matrix output(column_count, row_count);
      for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
          output.set(j, i, get(i, j));
        }
      }
      return output;
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
  Matrix matrix = inputMatrix(5, 4);
  Matrix transpose = matrix.transpose();
  std::cout << "Transposed matrix:\n";
  transpose.print();
}

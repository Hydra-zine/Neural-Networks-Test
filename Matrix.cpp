#include "Matrix.h"
#include <iostream>

Vector::Vector() {}

Vector::Vector(int size) { data.resize(size); }

int Vector::size() const { return data.size(); }

double &Vector::operator[](int index) { return data[index]; }

const double &Vector::operator[](int index) const { return data[index]; }

Vector Vector::multiply(double x) const {
  Vector result(size());

  for (int i = 0; i < size(); i++) {
    result[i] = data[i] * x;
  }

  return result;
}

Vector Vector::multiply(const Vector &v) const {
  Vector result(size());

  for (int i = 0; i < size(); i++) {
    result[i] = data[i] * v[i];
  }

  return result;
}

void Vector::print() const {
  for (double n : data) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}

Matrix::Matrix() {}

Matrix::Matrix(int rows, int cols) {
  data.resize(rows, std::vector<double>(cols));
}

int Matrix::rows() const { return data.size(); }

int Matrix::cols() const { return data[0].size(); }

std::vector<double> &Matrix::operator[](int index) { return data[index]; }

const std::vector<double> &Matrix::operator[](int index) const {
  return data[index];
}

Matrix Matrix::transpose() const {
  Matrix result(cols(), rows());

  for (int i = 0; i < rows(); i++) {
    for (int k = 0; k < cols(); k++) {
      result[k][i] = data[i][k];
    }
  }

  return result;
}

Vector Matrix::multiply(const Vector &x) const {
  Vector result(rows());

  for (int i = 0; i < rows(); i++) {
    result[i] = 0;
    for (int j = 0; j < x.size(); j++) {
      result[i] += data[i][j] * x[j];
    }
  }

  return result;
}

Matrix Matrix::multiply(double x) const {
  Matrix result(rows(), cols());

  for (int i = 0; i < rows(); i++) {
    for (int k = 0; k < cols(); k++) {
      result[i][k] = data[i][k] * x;
    }
  }

  return result;
}

Matrix outerProduct(const Vector &column, const Vector &row) {
  Matrix result(row.size(), column.size());

  for (int i = 0; i < row.size(); i++) {
    for (int k = 0; k < column.size(); k++) {
      result[i][k] = row[i] * column[k];
    }
  }

  return result;
}

Vector hadamard(const Vector &a, const Vector &b) {
  Vector result(a.size());

  for (int i = 0; i < a.size(); i++) {
    result[i] = a[i] * b[i];
  }

  return result;
}

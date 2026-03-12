#include "Matrix.h"
#include <iostream>

Vector::Vector() {}

Vector::Vector(int size) { data.resize(size); }

int Vector::size() const { return data.size(); }

double &Vector::operator[](int index) { return data[index]; }

const double &Vector::operator[](int index) const { return data[index]; }

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

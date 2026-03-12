#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Vector {
private:
  std::vector<double> data;

public:
  Vector();
  Vector(int size);

  int size() const;

  double &operator[](int index);
  const double &operator[](int index) const;

  void print() const;
};

class Matrix {
private:
  std::vector<std::vector<double>> data;

public:
  Matrix();
  Matrix(int rows, int columns);

  int rows() const;
  int cols() const;

  std::vector<double> &operator[](int index);
  const std::vector<double> &operator[](int index) const;

  Matrix transpose() const;
  Vector multiply(const Vector &v) const;

  void print() const;
};

#endif

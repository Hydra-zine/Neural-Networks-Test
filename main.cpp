#include <cmath>
#include <iostream>

using Vector = std::vector<double>;
using Matrix = std::vector<std::vector<double>>;

Vector matVecMultiply(const Matrix &W, const Vector &x) {
  Vector result(W.size());

  for (int i = 0; i < W.size(); i++) {
    result[i] = 0;
    for (int j = 0; j < x.size(); j++) {
      result[i] += W[i][j] * x[j];
    }
  }

  return result;
}

Vector add(const Vector &a, const Vector &b) {
  Vector c;
  for (int i = 0; i < a.size(); i++) {
    c.push_back(a[i] + b[i]);
  }
  return c;
}

double sigmoid(double x) { return 1 / (1 + std::exp(-x)); }

Vector softmax(const Vector &v) {
  Vector result;

  double sum = 0;

  for (double num : v) {
    sum += std::exp(num);
  }

  for (int i = 0; i < v.size(); i++) {
    result.push_back(std::exp(v[i]) / sum);
  }

  return result;
}

Vector applySigmoid(const Vector &v) {
  Vector u;
  for (double d : v) {
    u.push_back(sigmoid(d));
  }
  return u;
}

double crossEntropyLoss(const Vector &v) {
  double cost = 0;

  for (double num : v) {
    cost -= (num * std::log10(num));
  }

  return cost;
}

Matrix transpose(const Matrix &m) {
  Matrix result;

  for (int i = 0; i < m.size(); i++) {
    for (int k = 0; k < m[i].size(); k++) {
    }
  }
}

class NeuralNetwork {
private:
  Matrix W1;
  Vector b1;

  Matrix W2;
  Vector b2;

public:
  Vector forward(const Vector &input);
};

Vector NeuralNetwork::forward(const Vector &input) {
  // hidden
  Vector z1 = matVecMultiply(W1, input);
  z1 = add(z1, b1);
  Vector a1 = applySigmoid(z1);

  // output
  Vector z2 = matVecMultiply(W2, a1);
  z2 = add(z2, b2);
  Vector a2 = softmax(z2);

  return a2;
}

int main() { return 0; }

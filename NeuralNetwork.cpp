#include "NeuralNetwork.h"
#include <random>

NeuralNetwork::NeuralNetwork(int input, int hidden, int output) {

};

double sigmoid(double x) { return 1 / (1 + std::exp(-x)); }

Vector NeuralNetwork::softmax(const Vector &v) {
  Vector result(v.size());

  double sum = 0;

  for (int i = 0; i < v.size(); i++) {
    sum += std::exp(v[i]);
  }

  for (int i = 0; i < v.size(); i++) {
    result[i] = (std::exp(v[i]) / sum);
  }

  return result;
}

Vector applySigmoid(const Vector &v) {
  Vector u(v.size());
  for (int i = 0; i < v.size(); i++) {
    u[i] = (sigmoid(v[i]));
  }
  return u;
}

double crossEntropyLoss(const Vector &v) {
  double cost = 0;

  for (int i = 0; i < v.size(); i++) {
    cost -= (v[i] * std::log10(v[i]));
  }

  return cost;
}

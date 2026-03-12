#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Matrix.h"

class NeuralNetwork {
private:
  Matrix W1;
  Vector b1;

  Matrix W2;
  Vector b2;

  double sigmoid(double x);
  Vector applySigmoid(const Vector &v);
  Vector softmax(const Vector &v);
  double crossEntropyLoss(const Vector &v);

public:
  NeuralNetwork(int input, int hidden, int output);
  Vector forward(const Vector &input);
};

#endif

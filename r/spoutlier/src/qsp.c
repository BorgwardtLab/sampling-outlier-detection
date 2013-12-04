#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// main function called from the R program "spoutlier.R"
void qsp(double *X, int *rn, int *rd, double *Xs, int *sid, int *rns,
         double *result) {
  int i, j, point, n = *rn, d = *rd, ns = *rns;
  double sum, res;

  // compute the outlierness score qsp for each data point
  for (point = 0; point < n; point++) {
    res = 0;
    for (i = 0; i < ns; i++) {
      if (point != sid[i]) {
        sum = 0;
        for (j = 0; j < d; j++)
          sum += fabs(X[point + j * n] - Xs[i + j * ns]) *
                 fabs(X[point + j * n] - Xs[i + j * ns]);
        if (res == 0)
          res = sum;
        else if (sum < res && sum > 0)
          res = sum;
      }
    }
    result[point] = sqrt(res);
  }
}

// normalization called from the R program "spoutlier.R"
void normalize(double *X, int *rn, int *rd, double *X_means, double *result) {
  int i, j, flag, n = *rn, d = *rd;
  double sum;

  for (j = 0; j < d; j++) {
    flag = 0;
    sum = X[j * n];
    for (i = 1; i < n; i++) {
      if (sum != X[i + j * n]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      for (i = 0; i < n; i++)
        result[i + j * n] = X[i + j * n];
    } else if (flag == 1) {
      sum = 0;
      for (i = 0; i < n; i++)
        sum += (X[i + j * n] - X_means[j]) * (X[i + j * n] - X_means[j]);
      sum = sqrt(sum / (n - 1)); // unbiased SD
      for (i = 0; i < n; i++)
        result[i + j * n] = X[i + j * n] / sum;
    }
  }
}

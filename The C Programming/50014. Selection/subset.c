#include "subset.h"

int subset(int numbers[], int n, int K, int S) {
  if (S == 0) {
    return K == 0;
  }
  if (n < S) {
    return 0;
  }

  if (K < numbers[n - 1]) {
    return subset(numbers, n - 1, K, S);
  }
  return subset(numbers, n - 1, K, S) ||
         subset(numbers, n - 1, K - numbers[n - 1], S - 1);
}

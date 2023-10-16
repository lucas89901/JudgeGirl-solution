#include "constructTable.h"

#include <stdlib.h>

int **first_level[100];

int ***constructTable(int A[], int B[]) {
  int b_index = 0;
  for (int i = 0; A[i]; ++i) {
    first_level[i] = calloc(A[i] + 1, sizeof(first_level[0][0]));
    for (int j = 0; j < A[i]; ++j) {
      first_level[i][j] = B + b_index;
      while (B[b_index] != 0) {
        ++b_index;
      }
      ++b_index;
    }
  }
  return first_level;
}

#include "chasing.h"

#include <stdio.h>
#include <string.h>

void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
  memset(A, 0, a * sizeof(A[0]));
  memset(B, 0, b * sizeof(B[0]));
  char buffer[70];
  while (fgets(buffer, 70, stdin) != NULL) {
    char from = '\0', to = '\0';
    int n = -1, m = -1;
    char discard[64];
    if (sscanf(buffer, " %c %d %c %d %s", &from, &n, &to, &m, discard) != 4 ||
        from == '\0' || to == '\0' || n == -1 || m == -1) {
      printf("0\n");
      continue;
    }

    if (from == 'A') {
      if (to != 'B' || n < 0 || n >= a || m < 0 || m >= b) {
        printf("0\n");
        continue;
      }
      A[n] = &B[m];
    } else if (from == 'B') {
      if (to != 'C' || n < 0 || n >= b || m < 0 || m >= c) {
        printf("0\n");
        continue;
      }
      B[n] = &C[m];
    } else {
      printf("0\n");
      continue;
    }
    printf("1\n");
  }
}

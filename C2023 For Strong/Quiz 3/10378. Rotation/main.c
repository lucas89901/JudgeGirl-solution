#include <assert.h>
#include <stdio.h>

#include "rotate.h"

int main() {
  int array[MAX][MAX], check[MAX][MAX];
  int *P[MAX][MAX];

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      P[i][j] = &array[i][j];
      scanf("%d", &array[i][j]);
      check[i][j] = array[i][j];
    }
  }

  rotate(P, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      assert(check[i][j] == array[i][j]);
      printf("%d ", *(P[i][j]));
    }
    printf("\n");
  }

  return 0;
}

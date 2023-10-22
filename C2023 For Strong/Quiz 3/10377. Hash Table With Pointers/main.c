#include <stdio.h>

#include "count_collision.h"

int main() {
  int n;
  int a, b, c;
  scanf("%d", &n);
  scanf("%d%d%d", &a, &b, &c);

  int *ptr[n];
  int A[c];

  count_collision(ptr, A, n, a, b, c);

  for (int i = 0; i < c; i++) printf("%d ", A[i]);
  printf("\n");
  for (int i = 0; i < n; i++) printf("%d ", ptr[i] - A);

  return 0;
}

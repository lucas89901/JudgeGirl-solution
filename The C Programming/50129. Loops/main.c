#include <stdio.h>
#include <stdlib.h>

#include "loops.h"
#define MAXN 1000000
int main() {
  int N;
  int *A = (int *)malloc(sizeof(int) * MAXN);
  int **B = (int **)malloc(sizeof(int *) * MAXN);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", A + i);
  for (int i = 0, ptr; i < N; i++) {
    scanf("%d", &ptr);
    B[i] = A + ptr;
  }
  int ans[4];
  loops(N, A, B, ans);
  for (int i = 0; i < 4; i++) printf("%d\n", ans[i]);
  return 0;
}

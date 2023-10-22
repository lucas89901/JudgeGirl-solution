#include <stdio.h>
#include <stdlib.h>

#include "calRectArea.h"
#define MAXM 200

int main() {
  int N, M;
  scanf("%d%d", &N, &M);

  int *ptrMatrix;
  int matrix[N][N];
  int *ptrLeft[MAXM];
  int *ptrRight[MAXM];
  int x, y, w, h;

  ptrMatrix = &matrix[0][0];
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d%d", &x, &y, &w, &h);
    ptrLeft[i] = &matrix[x][y];
    ptrRight[i] = &matrix[x + w - 1][y + h - 1];
  }
  int area = calRectArea(N, M, ptrMatrix, ptrLeft, ptrRight);
  printf("%d\n", area);
}

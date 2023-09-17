#include <stdio.h>
#include <string.h>

int main() {
  int N, k, x, y;
  scanf("%d%d%d%d", &N, &k, &x, &y);

  int matrix[N][N];
  memset(matrix, 0, sizeof(matrix));

  matrix[x][y] = k;
  for (int i = k - 1, x_back = x, y_back = y; i >= 1; --i) {
    // It is guaranteed that 1 <= k <= N, so there will be no vertical position
    // changes.
    x_back = (x_back + 1) % N;
    y_back = (y_back - 1 + N) % N;
    matrix[x_back][y_back] = i;
  }
  for (int i = k + 1; i <= N * N; ++i) {
    if (matrix[(x - 1 + N) % N][(y + 1) % N] == 0) {
      // Move 1 squre diagonally up and right,
      x = (x - 1 + N) % N;
      y = (y + 1) % N;
    } else {
      // Move 1 square down.
      x = (x + 1) % N;
    }
    matrix[x][y] = i;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%d%c", matrix[i][j], " \n"[j == N - 1]);
    }
  }
  return 0;
}

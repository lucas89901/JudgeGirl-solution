#include <stdio.h>

int main() {
  int N, M;
  scanf("%d%d", &N, &M);

  int cube[N][N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        cube[i][j][k] = N * N * i + N * j + k;
      }
    }
  }

  for (int m = 0; m < M; ++m) {
    int type, layer;
    scanf("%d%d", &type, &layer);
    if (type == 0) {
      int rotated[N][N];
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          rotated[i][j] = cube[layer][N - 1 - j][i];
        }
      }
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          cube[layer][i][j] = rotated[i][j];
        }
      }
    } else {
      int rotated[N][N];
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          rotated[i][j] = cube[N - 1 - j][i][layer];
        }
      }
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          cube[i][j][layer] = rotated[i][j];
        }
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        printf("%d%c", cube[i][j][k], " \n"[k == N - 1]);
      }
    }
  }
  return 0;
}

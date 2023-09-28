#include <stdbool.h>
#include <stdio.h>

// Check if point (px, py) is in a shadow with a bottom-left point of (x, y).
inline bool IsInShadow(int px, int py, int L, int W, int x, int y) {
  return x <= px && px < x + W && y <= py && py < y + L;
}

int main() {
  int N, M, L, W, x, y, s, k;
  scanf("%d%d%d%d%d%d%d%d", &N, &M, &L, &W, &x, &y, &s, &k);
  int sun[M][N];
  for (int j = N - 1; j >= 0; --j) {
    for (int i = 0; i < M; ++i) {
      scanf("%d", &sun[i][j]);
    }
  }

  for (int step = 0; step <= k; ++step, x -= s, y -= s) {
#ifdef GP_DEBUG
    fprintf(stderr,
            "Bottom-left point of shadow after stepping %d steps: (%d, %d)\n",
            step, x, y);
#endif
    // The shadow still needs to move until it can reach the sun.
    if (x >= M || y >= N) {
      continue;
    }
    // The shadow has already left the sun.
    if (x + W - 1 < 0 || y + L - 1 < 0) {
      break;
    }

    for (int j = N - 1; j >= 0; --j) {
      for (int i = 0; i < M; ++i) {
        if (IsInShadow(i, j, L, W, x, y)) {
          printf("0");
        } else {
          printf("%d", sun[i][j]);
        }
        printf("%c", " \n"[i == M - 1]);
      }
    }
    printf("\n");
  }
  return 0;
}

#include <stdio.h>

inline int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {
  int N, M, L, W, x, y, s, k;
  scanf("%d%d%d%d%d%d%d%d", &N, &M, &L, &W, &x, &y, &s, &k);
  int sun[N][M];
  for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &sun[i][j]);
    }
  }

  // Calculate the steps needed initially for the shadow to touch the sun.
  // x - step * s < M => step > (x - M) / s
  int x_step = (x - M) / s + 1;
  int y_step = (y - N) / s + 1;
  int step = Max(0, Max(x_step, y_step));
  x -= step * s;
  y -= step * s;

  for (; step <= k; ++step, x -= s, y -= s) {
#ifdef GP_DEBUG
    fprintf(stderr,
            "Bottom-left point of shadow after stepping %d steps: (%d, %d)\n",
            step, x, y);
#endif
    // The shadow has already left the sun.
    if (x + W - 1 < 0 || y + L - 1 < 0) {
      break;
    }

    for (int i = N - 1; i >= 0; --i) {
      for (int j = 0; j < M; ++j) {
        if (x <= j && j < x + W && y <= i && i < y + L) {
          // Point (j, i) is in shadow.
          printf("0");
        } else {
          printf("%d", sun[i][j]);
        }
        printf("%c", " \n"[j == M - 1]);
      }
    }
    printf("\n");
  }
  return 0;
}

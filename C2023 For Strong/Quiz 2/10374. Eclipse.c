#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Check if point (pr, pc) is in a shadow with a bottom-left point of (r, c).
inline bool IsInShadow(int pr, int pc, int L, int W, int r, int c) {
  return r - L < pr && pr <= r && c <= pc && pc < c + W;
}

inline bool IsOverlapped(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                         int bx2, int by2) {
  return !(ax2 < bx1 || bx2 < ax1 || ay2 < by1 || by2 < ay1);
}

int main() {
  int N, M, L, W, x, y, s, k;
  scanf("%d%d%d%d%d%d%d%d", &N, &M, &L, &W, &x, &y, &s, &k);
  int sun[N][M];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &sun[i][j]);
    }
  }

  int r = N - 1 - y, c = x;
  bool has_covered = false;
  for (int step = 0; step <= k; ++step) {
#ifdef GP_DEBUG
    fprintf(stderr,
            "Bottom-left point of shadow after stepping %d steps: (%d, %d)\n",
            step, r, c);
#endif
    bool is_covered =
        IsOverlapped(0, 0, N - 1, M - 1, r - L + 1, c, r, c + W - 1);
    if (has_covered && !is_covered) {
      break;
    }

    if (is_covered) {
      has_covered = true;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          if (IsInShadow(i, j, L, W, r, c)) {
            printf("0");
          } else {
            printf("%d", sun[i][j]);
          }
          printf("%c", " \n"[j == M - 1]);
        }
      }
      printf("\n");
    }

    r += s;
    c -= s;
  }
  return 0;
}

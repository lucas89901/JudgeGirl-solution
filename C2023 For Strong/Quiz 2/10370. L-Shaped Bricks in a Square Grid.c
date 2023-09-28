#include <stdbool.h>
#include <stdio.h>

bool GreaterThan(int x1, int y1, int x2, int y2) {
  if (x1 == x2) {
    return y1 > y2;
  }
  return x1 > x2;
}

void Swap(int *x1, int *y1, int *x2, int *y2) {
  int tmp = *x1;
  *x1 = *x2;
  *x2 = tmp;

  tmp = *y1;
  *y1 = *y2;
  *y2 = tmp;
}

int main() {
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};

  int n;
  scanf("%d", &n);
  bool grid[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &grid[i][j]);
    }
  }

  int m;
  scanf("%d", &m);
  int x[m], y[m];
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  // Bubble sort.
  for (int i = m; i > 1; --i) {
    for (int j = 0; j < m - 1; ++j) {
      if (GreaterThan(x[j], y[j], x[j + 1], y[j + 1])) {
        Swap(&x[j], &y[j], &x[j + 1], &y[j + 1]);
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    int length[4] = {0, 0, 0, 0};
    for (int d = 0; d < 4; ++d) {
      for (int x2 = x[i], y2 = y[i];
           0 <= x2 && x2 < n && 0 <= y2 && y2 < n && grid[x2][y2];
           x2 += dx[d], y2 += dy[d]) {
        ++length[d];
      }
    }
#ifdef GP_DEBUG
    fprintf(stderr, "length = {%d,%d,%d,%d}\n", length[0], length[1], length[2],
            length[3]);
#endif

    if (length[0] > 1 && length[3] > 1) {
      printf("0 %d %d\n", length[3], length[0]);
    } else if (length[2] > 1 && length[3] > 1) {
      printf("1 %d %d\n", length[3], length[2]);
    } else if (length[1] > 1 && length[2] > 1) {
      printf("2 %d %d\n", length[1], length[2]);
    } else if (length[0] > 1 && length[1] > 1) {
      printf("3 %d %d\n", length[1], length[0]);
    }
  }
  return 0;
}

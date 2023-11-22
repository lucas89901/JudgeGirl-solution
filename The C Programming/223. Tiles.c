#include <stdio.h>

void Solve(int x, int y, int x_empty, int y_empty, int length, const int stop) {
  if (length == 1 || x == stop && y == stop) {
    return;
  }
  int x_mid = x + length / 2;
  int y_mid = y + length / 2;

  if (x_empty < x_mid) {
    if (y_empty < y_mid) {
      printf("3 %d %d\n", x_mid, y_mid);
      Solve(x, y, x_empty, y_empty, length / 2, stop);
      Solve(x_mid, y, x_mid, y_mid - 1, length / 2, stop);
      Solve(x, y_mid, x_mid - 1, y_mid, length / 2, stop);
      Solve(x_mid, y_mid, x_mid, y_mid, length / 2, stop);

    } else {
      printf("2 %d %d\n", x_mid, y_mid);
      Solve(x, y, x_mid - 1, y_mid - 1, length / 2, stop);
      Solve(x_mid, y, x_mid, y_mid - 1, length / 2, stop);
      Solve(x, y_mid, x_empty, y_empty, length / 2, stop);
      Solve(x_mid, y_mid, x_mid, y_mid, length / 2, stop);
    }
  } else {
    if (y_empty < y_mid) {
      printf("4 %d %d\n", x_mid, y_mid);
      Solve(x, y, x_mid - 1, y_mid - 1, length / 2, stop);
      Solve(x_mid, y, x_empty, y_empty, length / 2, stop);
      Solve(x, y_mid, x_mid - 1, y_mid, length / 2, stop);
      Solve(x_mid, y_mid, x_mid, y_mid, length / 2, stop);
    } else {
      printf("1 %d %d\n", x_mid, y_mid);
      Solve(x, y, x_mid - 1, y_mid - 1, length / 2, stop);
      Solve(x_mid, y, x_mid, y_mid - 1, length / 2, stop);
      Solve(x, y_mid, x_mid - 1, y_mid, length / 2, stop);
      Solve(x_mid, y_mid, x_empty, y_empty, length / 2, stop);
    }
  }
}

int main() {
  int l, m;
  scanf("%d %d", &l, &m);
  Solve(0, 0, l / 2, l / 2, l, l - m);
  return 0;
}

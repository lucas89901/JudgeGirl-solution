#include <stdio.h>

void Solve(int x, int y, int length, int x_hole, int y_hole) {
  if (length == 1) {
    return;
  }

  int x_mid = x + length / 2;
  int y_mid = y + length / 2;
  if (x_hole < x_mid) {
    if (y_hole < y_mid) {
      printf("4 %d %d\n", x_mid, y_mid);
      Solve(x, y, length / 2, x_hole, y_hole);
      Solve(x, y_mid, length / 2, x_mid - 1, y_mid);
      Solve(x_mid, y, length / 2, x_mid, y_mid - 1);
      Solve(x_mid, y_mid, length / 2, x_mid, y_mid);
    } else {
      printf("2 %d %d\n", x_mid, y_mid);
      Solve(x, y, length / 2, x_mid - 1, y_mid - 1);
      Solve(x, y_mid, length / 2, x_hole, y_hole);
      Solve(x_mid, y, length / 2, x_mid, y_mid - 1);
      Solve(x_mid, y_mid, length / 2, x_mid, y_mid);
    }
  } else {
    if (y_hole < y_mid) {
      printf("3 %d %d\n", x_mid, y_mid);
      Solve(x, y, length / 2, x_mid - 1, y_mid - 1);
      Solve(x, y_mid, length / 2, x_mid - 1, y_mid);
      Solve(x_mid, y, length / 2, x_hole, y_hole);
      Solve(x_mid, y_mid, length / 2, x_mid, y_mid);
    } else {
      printf("1 %d %d\n", x_mid, y_mid);
      Solve(x, y, length / 2, x_mid - 1, y_mid - 1);
      Solve(x, y_mid, length / 2, x_mid - 1, y_mid);
      Solve(x_mid, y, length / 2, x_mid, y_mid - 1);
      Solve(x_mid, y_mid, length / 2, x_hole, y_hole);
    }
  }
}

int main() {
  int l, x, y;
  scanf("%d %d %d", &l, &x, &y);
  Solve(0, 0, l, x, y);
  return 0;
}

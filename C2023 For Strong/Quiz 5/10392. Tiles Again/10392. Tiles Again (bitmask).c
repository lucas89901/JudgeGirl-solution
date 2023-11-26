#include <stdio.h>

// -x: 2, 4 -> 1, 3 (01, 11)
// -y: 3, 4 -> 2, 3 (10, 11)
// (-y)(-x)

void Solve(int x, int y, int length, int x_hole, int y_hole) {
  int x_mid = x + length / 2;
  int y_mid = y + length / 2;
  int type = ((y_hole < y_mid) << 1) + (x_hole < x_mid);
  printf("%d %d %d\n", type + 1, x_mid, y_mid);
  if (length == 2) {
    return;
  }

  if (type == 0) {
    Solve(x_mid, y_mid, length / 2, x_hole, y_hole);
  } else {
    Solve(x_mid, y_mid, length / 2, x_mid, y_mid);
  }
  if (type == 1) {
    Solve(x, y_mid, length / 2, x_hole, y_hole);
  } else {
    Solve(x, y_mid, length / 2, x_mid - 1, y_mid);
  }
  if (type == 2) {
    Solve(x_mid, y, length / 2, x_hole, y_hole);
  } else {
    Solve(x_mid, y, length / 2, x_mid, y_mid - 1);
  }
  if (type == 3) {
    Solve(x, y, length / 2, x_hole, y_hole);
  } else {
    Solve(x, y, length / 2, x_mid - 1, y_mid - 1);
  }
}

int main() {
  int l, x, y;
  scanf("%d %d %d", &l, &x, &y);
  if (l == 1) {
    return 0;
  }
  Solve(0, 0, l, x, y);
  return 0;
}

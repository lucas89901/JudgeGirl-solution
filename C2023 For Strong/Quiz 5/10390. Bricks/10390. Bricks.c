#include <stdio.h>

// -x: 2, 4, 6, 8 -> 1, 3, 5, 7 (001, 011, 101, 111)
// -y: 3, 4, 7, 8 -> 2, 3, 6, 7 (010, 011, 110, 111)
// -z: 5, 6, 7, 8 -> 4, 5, 6, 7 (100, 101, 110, 111)
// If we types 1-8 to 0-7, we get a 3-bit bitmask: (-z)(-y)(-x)

void Solve(int x_base, int y_base, int z_base, int length, int x_hole,
           int y_hole, int z_hole) {
  int x_mid = x_base + length / 2;
  int y_mid = y_base + length / 2;
  int z_mid = z_base + length / 2;
  int type =
      ((z_hole < z_mid) << 2) + ((y_hole < y_mid) << 1) + (x_hole < x_mid);
  printf("%d %d %d %d\n", type + 1, x_mid, y_mid, z_mid);
  if (length == 2) {
    return;
  }

  if (type == 0) {  // Hole is in (+x, +y, +z).
    Solve(x_mid, y_mid, z_mid, length / 2, x_hole, y_hole, z_hole);
  } else {
    Solve(x_mid, y_mid, z_mid, length / 2, x_mid, y_mid, z_mid);
  }
  if (type == 1) {  // Hole is in (-x, +y, +z).
    Solve(x_base, y_mid, z_mid, length / 2, x_hole, y_hole, z_hole);
  } else {
    Solve(x_base, y_mid, z_mid, length / 2, x_mid - 1, y_mid, z_mid);
  }
  if (type == 2) {  // Hole is in (+x, -y, +z).
    Solve(x_mid, y_base, z_mid, length / 2, x_hole, y_hole, z_hole);
  } else {
    Solve(x_mid, y_base, z_mid, length / 2, x_mid, y_mid - 1, z_mid);
  }
  if (type == 3) {  // Hole is in (-x, -y, +z).
    Solve(x_base, y_base, z_mid, length / 2, x_hole, y_hole, z_hole);
  } else {
    Solve(x_base, y_base, z_mid, length / 2, x_mid - 1, y_mid - 1, z_mid);
  }
  if (type == 4) {  // Hole is in (+x, +y, -z).
    Solve(x_mid, y_mid, z_base, length / 2, x_hole, y_hole, z_hole);
  } else {
    Solve(x_mid, y_mid, z_base, length / 2, x_mid, y_mid, z_mid - 1);
  }
  if (type == 5) {  // Hole is in (-x, +y, -z).
    Solve(x_base, y_mid, z_base, length / 2, x_hole, y_hole, z_hole);
  } else {
    Solve(x_base, y_mid, z_base, length / 2, x_mid - 1, y_mid, z_mid - 1);
  }
  if (type == 6) {  // Hole is in (+x, -y, -z).
    Solve(x_mid, y_base, z_base, length / 2, x_hole, y_hole, z_hole);
  } else {
    Solve(x_mid, y_base, z_base, length / 2, x_mid, y_mid - 1, z_mid - 1);
  }
  if (type == 7) {  // Hole is in (-x, -y, -z).
    Solve(x_base, y_base, z_base, length / 2, x_hole, y_hole, z_hole);
  } else {
    Solve(x_base, y_base, z_base, length / 2, x_mid - 1, y_mid - 1, z_mid - 1);
  }
}

int main() {
  int l, x, y, z;
  scanf("%d %d %d %d", &l, &x, &y, &z);
  Solve(0, 0, 0, l, x, y, z);
  return 0;
}

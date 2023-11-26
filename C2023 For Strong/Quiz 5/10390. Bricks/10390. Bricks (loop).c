#include <stdbool.h>
#include <stdio.h>

// -x: 2, 4, 6, 8 -> 1, 3, 5, 7 (001, 011, 101, 111)
// -y: 3, 4, 7, 8 -> 2, 3, 6, 7 (010, 011, 110, 111)
// -z: 5, 6, 7, 8 -> 4, 5, 6, 7 (100, 101, 110, 111)
// bitmask: (-z)(-y)(-x)

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

  // (+x, +y, +z), (-x, +y, +z), (+x, -y, +z), (-x, -y, +z),
  // (+x, +y, -z), (-x, +y, -z), (+x, -y, -z), (-x, -y, -z)
  for (int i = 0; i < 8; ++i) {
    if (type == i) {
      Solve(x_base + !(i & 1) * length / 2, y_base + !(i & 2) * length / 2,
            z_base + !(i & 4) * length / 2, length / 2, x_hole, y_hole, z_hole);
    } else {
      Solve(x_base + !(i & 1) * length / 2, y_base + !(i & 2) * length / 2,
            z_base + !(i & 4) * length / 2, length / 2, x_mid - (i & 1),
            y_mid - (bool)(i & 2), z_mid - (bool)(i & 4));
    }
  }
}

int main() {
  int l, x, y, z;
  scanf("%d %d %d %d", &l, &x, &y, &z);
  Solve(0, 0, 0, l, x, y, z);
  return 0;
}

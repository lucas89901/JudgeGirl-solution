#include <stdio.h>

int Distance(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  int xa, ya, ra, xb, yb, rb;
  scanf("%d%d%d%d%d%d", &xa, &ya, &ra, &xb, &yb, &rb);

  int x, y;
  while (scanf("%d%d", &x, &y) != EOF) {
    int distance_a = Distance(x, y, xa, ya);
    int distance_b = Distance(x, y, xb, yb);
    if (distance_a < ra * ra || distance_b < rb * rb) {
      printf("In\n");
    } else if (distance_a == ra * ra || distance_b == rb * rb) {
      printf("On\n");
    } else {
      printf("Out\n");
    }
  }
  return 0;
}

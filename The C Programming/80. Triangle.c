#include <stdio.h>

void Swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int tc = 0; tc < n; ++tc) {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    int a_squared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    int b_squared = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    int c_squared = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    // Sort increasing.
    if (a_squared > b_squared) {
      Swap(&a_squared, &b_squared);
    }
    if (b_squared > c_squared) {
      Swap(&b_squared, &c_squared);
    }
    if (a_squared > c_squared) {
      Swap(&a_squared, &c_squared);
    }

    if (a_squared == b_squared || b_squared == c_squared) {
      printf("isosceles\n");
      continue;
    }
    if (a_squared + b_squared < c_squared) {
      printf("obtuse\n");
    } else if (a_squared + b_squared == c_squared) {
      printf("right\n");
    } else {
      printf("acute\n");
    }
  }
  return 0;
}

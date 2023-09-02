#include <stdio.h>

int Cross(int a1, int a2, int b1, int b2) {
  return a1 * b2 - a2 * b1;
}

int main() {
  int a, b, c, d, e, f, g, h;
  for (int i = 0; i < 4; ++i) {
    scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
  }
  if (Cross(a, b, c, d) < 0 || Cross(c, d, e, f) < 0 || Cross(e, f, g, h) < 0 ||
      Cross(g, h, a, b) < 0) {
    printf("0\n");
    return 0;
  }

  printf("1\n");
  return 0;
}

#include <stdio.h>

int main() {
  int s, f, t;
  scanf("%d%d%d", &s, &f, &t);

  // a + b + c = s
  // 2a + 4b + 8c = f
  // a + b = t
  int crab = s - t;
  int rabbit = (f - 8 * crab) / 2 - t;
  int chicken = s - crab - rabbit;
  printf("%d\n%d\n%d\n", chicken, rabbit, crab);

  return 0;
}

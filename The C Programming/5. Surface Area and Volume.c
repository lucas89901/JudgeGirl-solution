#include <stdio.h>

int main() {
  int h, w, d;
  scanf("%d%d%d", &h, &w, &d);
  printf("%d\n%d\n", 2 * (h * w + w * d + h * d), h * w * d);
  return 0;
}

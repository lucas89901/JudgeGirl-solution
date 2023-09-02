#include <stdio.h>
#include <stdlib.h>

int main() {
  int w, a, b, c, d, e;
  scanf("%d%d%d%d%d%d", &w, &a, &b, &c, &d, &e);

  int length = a + b + c + d + e + 2;
  if (b > 0) {
    length += d + e;
  } else {
    length += abs(d - e);
  }
  printf("%d\n", length * length + w * w);

  return 0;
}

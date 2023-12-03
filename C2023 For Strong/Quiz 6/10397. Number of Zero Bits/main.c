#include <stdio.h>

#include "numZeroBits.h"

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    GiantUnsignedInt giantNum;
    for (int i = 0; i < n; i++) scanf("%llu", &giantNum.array[i]);
    giantNum.n = n;
    printf("%d\n", numZeroBits(&giantNum));
  }
  return 0;
}

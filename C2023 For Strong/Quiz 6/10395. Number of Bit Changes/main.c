#include <stdio.h>

#include "numBitChanges.h"

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    GiantUnsignedInt giantNum;
    for (int i = 0; i < n; i++) scanf("%llu", &giantNum.array[i]);
    giantNum.n = n;
    printf("%d\n", numBitChanges(&giantNum));
  }
  return 0;
}

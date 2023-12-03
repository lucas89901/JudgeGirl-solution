#include "numZeroBits.h"

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int numZeroBits(GiantUnsignedInt *giantNum) {
  int answer = 0;
  int count = 0;
  for (int i = giantNum->n - 1; i >= 0; --i) {
    for (int j = 0; j < 64; ++j) {
      if (giantNum->array[i] & 1) {
        answer = Max(answer, count);
        count = 0;
      } else {
        ++count;
      }
      giantNum->array[i] >>= 1;
    }
  }
  answer = Max(answer, count);
  return answer;
}

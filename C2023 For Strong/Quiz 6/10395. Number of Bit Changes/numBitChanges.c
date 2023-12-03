#include "numBitChanges.h"

#include <stdint.h>

int numBitChanges(GiantUnsignedInt *giantNum) {
  int answer = 0;
  for (int i = giantNum->n - 1; i >= 0; --i) {
    if ((giantNum->array[i] & 1) !=
        (giantNum->array[(i + 1) % giantNum->n] >> 63 & 1)) {
      ++answer;
    }
    uint64_t now = giantNum->array[i];
    for (int i = 0; i < 63; ++i) {
      if ((now >> 1 & 1) != (now & 1)) {
        ++answer;
      }
      now >>= 1;
    }
  }
  return answer;
}

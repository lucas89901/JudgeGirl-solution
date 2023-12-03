#include <stdint.h>
#define ARRAYSIZE 1000

typedef struct giantUnsignedInt {
  uint64_t array[ARRAYSIZE];
  int n;
} GiantUnsignedInt;

int numZeroBits(GiantUnsignedInt *giantNum);

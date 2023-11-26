#include <stdio.h>

#include "hanoi.h"

void initialize(struct hanoi *hn, int n) {
  hn->size[0] = n;
  hn->size[1] = 0;
  hn->size[2] = 0;
  for (int i = 0; i < n; ++i) {
    hn->rods[0][i] = n - 1 - i;
  }
}

void moveHanoi(struct hanoi *hn, int src, int dst) {
  hn->rods[dst][hn->size[dst]++] = hn->rods[src][--hn->size[src]];
}

void printHanoi(struct hanoi *hn) {
  for (int i = 0; i < 3; ++i) {
    printf("%d:", i);
    for (int j = 0; j < hn->size[i]; ++j) {
      printf(" %d", hn->rods[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

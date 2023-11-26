#include <stdio.h>

#include "hanoi.h"
#define MAXDISK 10
#define NUMROD 3

void initialize(struct hanoi *hn, int n);
void moveHanoi(struct hanoi *hn, int src, int dst);
void printHanoi(struct hanoi *hn);

void hanoi(struct hanoi *hn, int n, int src, int dst, int buffer) {
  if (n == 1) {
    moveHanoi(hn, src, dst);
    printHanoi(hn);
  } else {
    hanoi(hn, n - 1, src, buffer, dst);
    moveHanoi(hn, src, dst);
    printHanoi(hn);
    hanoi(hn, n - 1, buffer, dst, src);
  }
}
int main(void) {
  int n;
  struct hanoi hn;

  scanf("%d", &n);

  initialize(&hn, n);
  printHanoi(&hn);
  hanoi(&hn, n, 0, 2, 1);

  return 0;
}

#include "count.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Count {
  int count;
  int *ptr;
} Count;

int Find(Count counts[], int size, int *target) {
  for (int i = 0; i < size; ++i) {
    if (counts[i].ptr == target) {
      return i;
    }
  }
  return -1;
}

int Compare(const void *lhs2, const void *rhs2) {
  const Count *lhs = lhs2;
  const Count *rhs = rhs2;
  if (lhs->count == rhs->count) {
    return (*lhs->ptr > *rhs->ptr) - (*lhs->ptr < *rhs->ptr);
  }
  return (lhs->count > rhs->count) - (lhs->count < rhs->count);
}

void count(int **p[]) {
  int size = 0;
  Count counts[512];
  for (size_t i = 0; p[i]; ++i) {
    int found = Find(counts, size, *p[i]);
    if (found == -1) {
      counts[size++] = (Count){.count = 1, .ptr = *p[i]};
    } else {
      ++counts[found].count;
    }
  }
  qsort(counts, size, sizeof(counts[0]), Compare);

  for (int i = 0; i < size; ++i) {
    printf("%d %d\n", *counts[i].ptr, counts[i].count);
  }
}

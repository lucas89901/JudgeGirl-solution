#include "count_collision.h"

void count_collision(int *ptr[], int A[], int n, int a, int b, int c) {
  // A[i]: Number of pointers that point to A[i].
  for (int i = 0; i < c; ++i) {
    A[i] = 0;
  }

  for (int i = 0; i < n; ++i) {
    int hash = (a * i + b) % c;
    ptr[i] = &A[hash];
    ++A[hash];
  }

  // A[i]: Number of collisions.
  for (int i = 0; i < c; ++i) {
    if (A[i] > 0) {
      --A[i];
    }
  }
}

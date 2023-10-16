#include <stdio.h>

void merge(int A[], int B[], int *a[], int *b[]) {
  int index_a = 0, index_b = 0;
  while (1) {
    if (A[index_a] < B[index_b]) {
      if (!a[index_a]) {  // Reached end of array A and a.
        a[index_a] = &B[index_b];
        break;
      } else if (B[index_b] < A[index_a + 1]) {
        a[index_a] = &B[index_b];
      }
      ++index_a;
    } else {
      if (!b[index_b]) {  // Reached end of array B and b.
        b[index_b] = &A[index_a];
        break;
      } else if (A[index_a] < B[index_b + 1]) {
        b[index_b] = &A[index_a];
      }
      ++index_b;
    }
  }
}

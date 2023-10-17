#include "fill_array.h"

void fill_array(int *ptr[], int n) {
  for (int *p = ptr[0]; p != ptr[n - 1] + 1; ++p) {
    *p = -1;
  }
  for (int i = 0; i < n; ++i) {
    *ptr[i] = i;
  }

  int *left = ptr[0];
  for (int *right = ptr[0] + 1; right != ptr[n - 1] + 1; ++right) {
    if (*right != -1) {
      for (int *fill = left + 1; fill != right; ++fill) {
        *fill = *left + *right;
      }
      left = right;
    }
  }
}

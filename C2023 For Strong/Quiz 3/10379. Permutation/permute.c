#include "permute.h"

#include <stddef.h>

void permute(int *ptrArray[MAX], int *ptrPerms[MAX]) {
  for (int i = 0; ptrPerms[i] != NULL; ++i) {
    int *old_ptr_array[MAX];
    for (int j = 0; ptrArray[j] != NULL; ++j) {
      old_ptr_array[j] = ptrArray[j];
    }
    for (int j = 0; ptrArray[j] != NULL; ++j) {
      ptrArray[j] = old_ptr_array[ptrPerms[i][j]];
    }
  }
}

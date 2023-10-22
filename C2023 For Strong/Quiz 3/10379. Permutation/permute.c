#include "permute.h"

#include <stddef.h>
#include <stdio.h>

void permute(int *ptrArray[MAX], int *ptrPerms[MAX]) {
  int *array = ptrArray[0];
  for (int i = 0; ptrPerms[i] != NULL; ++i) {
    for (int j = 0; ptrArray[j] != NULL; ++j) {
      ptrArray[j] = array + ptrPerms[i][ptrArray[j] - array];
    }
  }
}

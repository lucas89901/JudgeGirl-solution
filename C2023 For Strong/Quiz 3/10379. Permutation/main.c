#include <assert.h>
#include <stdio.h>

#include "permute.h"

int main() {
  int n, array[MAX], check[MAX];
  int *ptrArray[MAX];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    ptrArray[i] = &array[i];
    scanf("%d", &array[i]);
    check[i] = array[i];
  }
  ptrArray[n] = NULL;

  int m, perms[MAX][MAX];
  int *ptrPerms[MAX];
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) scanf("%d", &perms[i][j]);
    ptrPerms[i] = perms[i];
  }
  ptrPerms[m] = NULL;

  permute(ptrArray, ptrPerms);

  for (int i = 0; i < n; i++) {
    assert(array[i] == check[i]);
    printf("%d ", *(ptrArray[i]));
  }

  return 0;
}

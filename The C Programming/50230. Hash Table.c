#include <stdio.h>

int Find(int arr[], int size, int target) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;  // Not found.
}

int main() {
  int S, C;
  scanf("%d%d", &S, &C);
  int table[S][C];
  for (int i = 0; i < S; ++i) {
    for (int j = 0; j < C; ++j) {
      table[i][j] = -1;
    }
  }

  int k;
  while (scanf("%d", &k) != EOF) {
    int hash = (77 * k + 2222) % S;
    int index = Find(table[hash], C, k);
    if (index == -1) {
      table[hash][Find(table[hash], C, -1)] = k;
    } else {
      printf("%d %d\n", k, hash);
      table[hash][index] = -1;
    }
  }
  return 0;
}

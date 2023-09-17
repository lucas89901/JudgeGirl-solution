#include <stdio.h>
#include <string.h>

typedef struct Cube {
  int value, layer, x, y;
} Cube;

int Find(Cube arr[], int size, int target) {
  for (int i = 0; i < size; ++i) {
    if (arr[i].value == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int N, S, C;
  scanf("%d%d%d", &N, &S, &C);

  const Cube kEmpty = {-1, -1, -1, -1};
  Cube hash_table[S][C];
  memset(hash_table, 0xff, sizeof(hash_table));

  Cube exposed_pair[2] = {kEmpty, kEmpty};
  int tower[N][N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= i; ++k) {
        scanf("%d", &tower[i][j][k]);
        if (j == i || k == i) {  // Is exposed.
          int hash = (77 * tower[i][j][k] + 2222) % S;
          int index = Find(hash_table[hash], C, tower[i][j][k]);
          if (index == -1) {  // Not in hash table.
            hash_table[hash][Find(hash_table[hash], C, -1)] =
                (Cube){tower[i][j][k], i, j, k};
          } else {
            printf("%d", tower[i][j][k]);
            exposed_pair[0] = hash_table[hash][index];
            hash_table[hash][index] = kEmpty;
            exposed_pair[1] = (Cube){tower[i][j][k], i, j, k};
          }
        }
      }
    }
  }

  while (exposed_pair[0].value != -1) {
    Cube underneath[2] = {kEmpty, kEmpty};
    for (int i = 0; i < 2; ++i) {
      if (exposed_pair[i].layer + 1 < N) {
        underneath[i] = (Cube){tower[exposed_pair[i].layer + 1]
                                    [exposed_pair[i].x][exposed_pair[i].y],
                               exposed_pair[i].layer + 1, exposed_pair[i].x,
                               exposed_pair[i].y};
      }
      exposed_pair[i] = kEmpty;
    }

    for (int i = 0; i < 2; ++i) {
      if (underneath[i].value == -1) {
        continue;
      }

      int hash = (77 * underneath[i].value + 2222) % S;
      int index = Find(hash_table[hash], C, underneath[i].value);
      if (index == -1) {
        hash_table[hash][Find(hash_table[hash], C, -1)] = underneath[i];
      } else {
        printf(" %d", underneath[i].value);
        exposed_pair[0] = hash_table[hash][index];
        hash_table[hash][index] = kEmpty;
        exposed_pair[1] = underneath[i];
      }
    }
  }
  printf("\n");
  return 0;
}

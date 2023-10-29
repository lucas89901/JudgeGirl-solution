#include <stdint.h>
#include <stdio.h>
#include <string.h>

const int C = 10;

typedef struct Data {
  char const *str;
  int j, k;
} Data;
const Data kNull = {NULL, -1, -1};

int Hash(const char str[], const int K) {
  int64_t hash = 0;
  for (int size = strlen(str), i = 0; i < size; i++) {
    hash = (hash * 29 + str[i] - 'a') % K;
  }
  return hash;
}

int Find(const Data hash_table[][C], const int hash, const char target[]) {
  for (int i = 0; i < C; ++i) {
    if (hash_table[hash][i].str &&
        strcmp(hash_table[hash][i].str, target) == 0) {
      return i;
    }
  }
  return -1;
}

int FindEmpty(const Data hash_table[][C], const int hash) {
  for (int i = 0; i < C; ++i) {
    if (!hash_table[hash][i].str) {
      return i;
    }
  }
  return -1;
}

void FindExposedPair(const int N, const int K, const char tower[N][N][N][6],
                     const int level[N][N], Data hash_table[][C], int j, int k,
                     int exposed[2][2]) {
  const char *cubic_str = tower[level[j][k]][j][k];
  int hash = Hash(cubic_str, K);
  int found = Find(hash_table, hash, cubic_str);
  if (found == -1) {
    hash_table[hash][FindEmpty(hash_table, hash)] = (Data){cubic_str, j, k};
  } else {
    exposed[0][0] = j;
    exposed[0][1] = k;
    exposed[1][0] = hash_table[hash][found].j;
    exposed[1][1] = hash_table[hash][found].k;
    hash_table[hash][found] = kNull;
  }
}

int main() {
  int N;
  scanf("%d", &N);
  const int K = N * N;

  Data hash_table[K][C];
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < C; ++j) {
      hash_table[i][j] = kNull;
    }
  }

  int level[N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      level[i][j] = i;
      level[j][i] = i;
    }
    level[i][i] = i;
  }

  int exposed[2][2] = {{-1, -1}, {-1, -1}};
  char tower[N][N][N][6];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= i; ++k) {
        scanf("%s", tower[i][j][k]);
        if (j >= i || k >= i) {
          FindExposedPair(N, K, tower, level, hash_table, j, k, exposed);
        }
      }
    }
  }

  while (exposed[0][0] != -1) {
    int exposed0_level = level[exposed[0][0]][exposed[0][1]];
    printf("%s\n", tower[exposed0_level][exposed[0][0]][exposed[0][1]]);

    int new_exposed[2][2] = {{-1, -1}, {-1, -1}};
    for (int i = 0; i < 2; ++i) {
      ++level[exposed[i][0]][exposed[i][1]];
      if (level[exposed[i][0]][exposed[i][1]] < N) {
        FindExposedPair(N, K, tower, level, hash_table, exposed[i][0],
                        exposed[i][1], new_exposed);
      }
    }
    memcpy(exposed, new_exposed, sizeof(new_exposed));
  }
  return 0;
}

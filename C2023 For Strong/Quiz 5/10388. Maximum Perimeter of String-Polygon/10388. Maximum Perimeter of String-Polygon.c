#include <stdio.h>
#include <string.h>

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

void Solve(const int N, const char strings[N][101], const char first, int n,
           int start, int length, int *answer) {
#ifdef GP_DEBUG
  fprintf(stderr, "n=%d,start=%d,length=%d\n", n, start, length);
#endif
  if (n == N - 1) {
    char *found = strrchr(strings[n], first);
    if (found == NULL) {
      return;
    }
#ifdef GP_DEBUG
    fprintf(stderr, "new_length=%d\n", length + (found - strings[n]) - start);
#endif
    *answer = Max(*answer, length + (found - strings[n]) - start);
    return;
  }

  int last_index[128];
  memset(last_index, -1, sizeof(last_index));
  for (int i = start, size = strlen(strings[n]); i < size; ++i) {
    last_index[strings[n][i]] = i;
  }

  for (int i = 0; i < 128; ++i) {
    if (last_index[i] == -1) {
      continue;
    }
    char *found_in_next = strchr(strings[n + 1], i);
    if (found_in_next == NULL) {
      continue;
    }
    int next_start = found_in_next - strings[n + 1];
    Solve(N, strings, first, n + 1, next_start, length + last_index[i] - start,
          answer);
  }
}

int main() {
  char strings[20][101];
  int size = 0;
  while (scanf("%s", strings[size]) != EOF) {
    ++size;
  }

  int first_index[128];
  memset(first_index, -1, sizeof(first_index));
  for (int i = strlen(strings[0]) - 1; i >= 0; --i) {
    first_index[strings[0][i]] = i;
  }

  int answer = -1;
  for (int i = 0; i < 128; ++i) {
    if (first_index[i] == -1) {
      continue;
    }
    Solve(size, strings, i, 0, first_index[i], 0, &answer);
  }
  printf("%d\n", answer);
  return 0;
}

#include "loops.h"

#include <limits.h>
#include <stdbool.h>
#include <string.h>

int Min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

void loops(int N, int *A, int *B[], int ans[4]) {
  ans[0] = INT_MIN;
  ans[1] = INT_MAX;
  ans[2] = INT_MIN;
  ans[3] = INT_MAX;

  bool visited[N];
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < N; ++i) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    int length = 1;
    int min = A[i];
    int max = A[i];

    for (int next = B[i] - A; next != i; next = B[next] - A) {
      visited[next] = true;
      ++length;
      min = Min(min, A[next]);
      max = Max(max, A[next]);
    }

    if (length > ans[0]) {
      ans[0] = length;
      ans[2] = max;
    } else if (length == ans[0]) {
      ans[2] = Max(ans[2], max);
    }
    if (length < ans[1]) {
      ans[1] = length;
      ans[3] = min;
    } else if (length == ans[1]) {
      ans[3] = Min(ans[3], min);
    }
  }
}

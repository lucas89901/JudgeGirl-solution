#include <stdint.h>
#include <stdio.h>
#include <string.h>

int Min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int Solve(int N, int distance[][N], int dp[][1U << N], int end,
          uint32_t visited) {
  if (dp[end][visited] != 0x3f3f3f3f) {
    return dp[end][visited];
  }

  for (int i = 1; i < N; ++i) {
    if (i != end && visited & 1U << i) {
      dp[end][visited] = Min(
          dp[end][visited],
          Solve(N, distance, dp, i, visited & ~(1U << end)) + distance[i][end]);
    }
  }
  return dp[end][visited];
}

int main() {
  int N;
  scanf("%d", &N);
  int distance[N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &distance[i][j]);
    }
  }

  int dp[N][1U << N];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  // Initialize first step.
  for (int i = 1; i < N; ++i) {
    dp[i][1U << i] = distance[0][i];
  }
  printf("%d\n", Solve(N, distance, dp, 0, (1U << N) - 1));
  return 0;
}

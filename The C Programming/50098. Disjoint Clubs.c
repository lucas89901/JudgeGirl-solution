#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool Solve(int N, int K, uint64_t clubs[], int id, int size, uint64_t chosen,
           int answer[]) {
  if (size == K) {
    return true;
  }
  if (size + N - id < K) {
    return false;
  }

  if ((chosen & clubs[id]) == 0) {
    answer[size] = id;
    if (Solve(N, K, clubs, id + 1, size + 1, chosen | clubs[id], answer)) {
      return true;
    }
  }
  return Solve(N, K, clubs, id + 1, size, chosen, answer);
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  uint64_t clubs[N];
  memset(clubs, 0, sizeof(clubs));
  for (int i = 0; i < N; ++i) {
    int M;
    scanf("%d", &M);
    for (int j = 0; j < M; ++j) {
      int member;
      scanf("%d", &member);
      clubs[i] |= 1ULL << member;
    }
  }

  int answer[K];
  Solve(N, K, clubs, 0, 0, 0, answer);
  for (int i = 0; i < K; ++i) {
    printf("%d\n", answer[i]);
  }
  return 0;
}

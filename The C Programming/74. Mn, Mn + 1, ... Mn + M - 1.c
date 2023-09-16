#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  scanf("%d", &N);
  int numbers[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d", &numbers[i]);
  }
  int M;
  scanf("%d", &M);

  int answer[M];
  memset(answer, 0, M * sizeof(answer[0]));
  for (int i = 0; i < N; ++i) {
    ++answer[numbers[i] % M];
  }
  for (int i = 0; i < M; ++i) {
    printf("%d\n", answer[i]);
  }
  return 0;
}

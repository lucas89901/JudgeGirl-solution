#include <stdio.h>

int main() {
  char N[3], M[8];
  scanf("%s %s", N, M);

  int answer = 0;
  for (size_t i = 0; i < 6; ++i) {
    if (M[i] == N[0] && M[i + 1] == N[1]) {
      ++answer;
    }
  }
  printf("%d\n", answer);

  return 0;
}

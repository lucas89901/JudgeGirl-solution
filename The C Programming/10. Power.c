#include <stdio.h>

int main() {
  int n, i;
  scanf("%d%d", &n, &i);

  int answer = 1;
  for (int j = 1; j <= i; ++j) {
    answer *= n;
  }
  printf("%d\n", answer);

  return 0;
}

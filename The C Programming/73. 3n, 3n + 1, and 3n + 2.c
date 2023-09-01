#include <stdio.h>

int main() {
  int answer[3] = {0, 0, 0};
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++answer[x % 3];
  }
  printf("%d %d %d\n", answer[0], answer[1], answer[2]);
  return 0;
}

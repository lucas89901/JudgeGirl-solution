#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int answer = 0;
  int x_first, y_first;
  scanf("%d%d", &x_first, &y_first);

  int x1 = x_first, y1 = y_first;
  for (int i = 1; i < n; ++i) {
    int x2, y2;
    scanf("%d%d", &x2, &y2);
    answer += x1 * y2 - x2 * y1;
    x1 = x2;
    y1 = y2;
  }
  answer += x1 * y_first - x_first * y1;

  printf("%d\n", answer);
  return 0;
}

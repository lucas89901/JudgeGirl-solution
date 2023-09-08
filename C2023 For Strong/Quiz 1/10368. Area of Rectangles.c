#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int x1, y1, w1, h1;
  scanf("%d%d%d%d", &x1, &y1, &w1, &h1);
  int answer = w1 * h1;
  for (int i = 0; i < N - 1; ++i) {
    int x2, y2, w2, h2;
    scanf("%d%d%d%d", &x2, &y2, &w2, &h2);
    answer += w2 * h2;
    answer -= (x1 + w1 - x2) * (y1 + h1 - y2);  // Overlapped area.

    x1 = x2;
    y1 = y2;
    w1 = w2;
    h1 = h2;
  }

  printf("%d\n", answer);
  return 0;
}

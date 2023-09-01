#include <stdio.h>

int main() {
  int x;
  scanf("%d", &x);

  if (x <= 0) {
    printf("%d\n", -100);
    return 0;
  }

  int score = 0;
  if (x % 3 == 0) {
    score += 3;
  }
  if (x % 5 == 0) {
    score += 5;
  }
  if (100 <= x && x <= 200) {
    score += 50;
  } else {
    score -= 50;
  }
  printf("%d\n", score);

  return 0;
}

#include <stdio.h>

int main() {
  int last;
  scanf("%d", &last);

  int now;
  int count = 1;
  while (scanf("%d", &now) != EOF) {
    if (last > 0 == now > 0) {  // `last` and `now` has the same sign.
      ++count;
    } else {
      if (last < 0) {
        count = -count;
      }
      printf("%d ", count);

      count = 1;
    }
    last = now;
  }

  if (last < 0) {
    count = -count;
  }
  printf("%d\n", count);
  return 0;
}

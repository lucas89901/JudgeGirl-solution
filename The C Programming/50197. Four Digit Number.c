#include <stdio.h>

int Min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {
  int k;
  scanf("%d", &k);

  for (int first = 1; first <= 9; ++first) {
    for (int second = Max(0, first - k); second <= Min(9, first + k);
         ++second) {
      for (int third = Max(0, second - k); third <= Min(9, second + k);
           ++third) {
        for (int fourth = Max(0, third - k); fourth <= Min(9, third + k);
             ++fourth) {
          printf("%d%d%d%d\n", first, second, third, fourth);
        }
      }
    }
  }
  return 0;
}

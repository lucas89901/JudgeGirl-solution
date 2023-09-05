#include <stdbool.h>
#include <stdio.h>

int LongestCommonSuffix(int a, int b) {
  int length = 0;
  while (a != 0 && b != 0 && a % 10 == b % 10) {
    ++length;
    a /= 10;
    b /= 10;
  }
  return length;
}

int main() {
  int special[3];
  for (int i = 0; i < 3; ++i) {
    scanf("%d", &special[i]);
  }
  int first[3];
  for (int i = 0; i < 3; ++i) {
    scanf("%d", &first[i]);
  }

  int sum = 0;
  int lottery;
  while (scanf("%d", &lottery) != EOF) {
    // Check special prize numbers.
    bool end = false;
    for (int i = 0; i < 3; ++i) {
      if (lottery == special[i]) {
        sum += 2000000;
        end = true;
        break;
      }
    }
    if (end) {
      continue;
    }

    // Check first prize numbers.
    for (int i = 0; i < 3; ++i) {
      switch (LongestCommonSuffix(lottery, first[i])) {
        case 8:
          sum += 200000;
          break;
        case 7:
          sum += 40000;
          break;
        case 6:
          sum += 10000;
          break;
        case 5:
          sum += 4000;
          break;
        case 4:
          sum += 1000;
          break;
        case 3:
          sum += 200;
      }
    }
  }
  printf("%d\n", sum);
  return 0;
}

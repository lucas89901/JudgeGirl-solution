#include <stdbool.h>
#include <stdio.h>

int Power(int base, int power) {
  int result = 1;
  for (int i = 0; i < power; ++i) {
    result *= base;
  }
  return result;
}

int Sum(int a, int b, int c, int d, int power) {
  return Power(a, power) + Power(b, power) + Power(c, power) + Power(d, power);
}

bool IsValid(int b, int c, int d, int sum, int squared_sum, int cubic_sum,
             int quartic_sum) {
  return b + c + d < sum && Sum(0, b, c, d, 2) < squared_sum &&
         Sum(0, b, c, d, 3) < cubic_sum && Sum(0, b, c, d, 4) < quartic_sum;
}

int main() {
  int sum, squared_sum, cubic_sum, quartic_sum;
  scanf("%d%d%d%d", &sum, &squared_sum, &cubic_sum, &quartic_sum);
  for (int d = 1; IsValid(0, 0, d, sum, squared_sum, cubic_sum, quartic_sum);
       ++d) {
    for (int c = d + 1;
         IsValid(0, c, d, sum, squared_sum, cubic_sum, quartic_sum); ++c) {
      for (int b = c + 1;
           IsValid(b, c, d, sum, squared_sum, cubic_sum, quartic_sum); ++b) {
        int a = sum - b - c - d;
        if (Sum(a, b, c, d, 2) == squared_sum &&
            Sum(a, b, c, d, 3) == cubic_sum &&
            Sum(a, b, c, d, 4) == quartic_sum) {
          printf("%d\n%d\n%d\n%d\n", a, b, c, d);
          return 0;
        }
      }
    }
  }

  printf("-1\n");
  return 0;
}

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  long double average = 0;
  long double variance = 0;
  for (int i = 0; i < n; ++i) {
    long double x;
    scanf("%Lf", &x);
    average += x;
    variance += x * x;
  }
  average /= n;
  variance = variance / n - average * average;

  printf("%Lf\n%Lf\n", average, variance);
  return 0;
}

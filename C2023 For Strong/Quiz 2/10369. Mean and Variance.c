#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  double x[n];
  double average = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &x[i]);
    average += x[i];
  }
  average /= n;

  double variance = 0;
  for (int i = 0; i < n; ++i) {
    variance += (x[i] - average) * (x[i] - average);
  }
  variance /= n;

  printf("%lf\n%lf\n", average, variance);
  return 0;
}

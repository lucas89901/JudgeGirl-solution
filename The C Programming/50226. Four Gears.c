#include <stdbool.h>
#include <stdio.h>

int Gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return Gcd(b, a % b);
}

int Lcm(int a, int b) {
  return a * b / Gcd(a, b);
}

int main() {
  int gears[4];
  while (scanf("%d%d%d%d", &gears[0], &gears[1], &gears[2], &gears[3]) != EOF) {
    int lcm = 1;
    for (int i = 0; i < 4; ++i) {
      lcm = Lcm(lcm, gears[i]);
    }
    printf("%d\n", lcm / gears[0]);
  }
  return 0;
}

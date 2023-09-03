#include <stdio.h>
#include <stdlib.h>

int Gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return Gcd(b, a % b);
}

int main() {
  int a, b, c, d, e, f, g;
  scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

  // Convert mixed fractions to improper fractions b/c and f/g.
  if (a < 0) {
    b = a * c - b;
  } else {
    b = a * c + b;
  }
  if (e < 0) {
    f = e * g - f;
  } else {
    f = e * g + f;
  }

  int i, j;
  if (d == 0) {  // Addition.
    i = b * g + c * f;
    j = c * g;
  } else if (d == 1) {  // Subtraction.
    i = b * g - c * f;
    j = c * g;
  } else if (d == 2) {  // Multiplication.
    i = b * f;
    j = c * g;
  } else {  // Divison.
    i = b * g;
    j = c * f;
  }

  int gcd = Gcd(abs(i), j);
  i /= gcd;
  j /= gcd;
  printf("%d\n%d\n%d\n", i / j, abs(i % j), j);

  return 0;
}

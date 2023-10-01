#include <stdio.h>

#include "dividePolynomial.h"

#define MAX 2000 + 1

void readPolynomial(int p[]) {
  scanf("%d", &p[0]);
  for (int i = 1; i <= p[0] + 1; i++) scanf("%d", &p[i]);
}

void printPolynomial(int p[]) {
  for (int i = 0; i <= p[0]; i++) printf("%d ", p[i]);
  printf("%d", p[p[0] + 1]);
}

int main() {
  int n, f[MAX], g[MAX];
  scanf("%d", &n);
  while (n--) {
    readPolynomial(f);
    readPolynomial(g);

    dividePolynomial(f, g);

    printPolynomial(f);
    printf("\n");
    printPolynomial(g);
    if (n) printf("\n");
  }
  return 0;
}

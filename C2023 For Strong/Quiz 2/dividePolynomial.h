// void Print(int a[], int size) {
//   for (int i = 0; i < size; ++i) {
//     fprintf(stderr, "%d ", a[i]);
//   }
//   fprintf(stderr, "\n");
// }

void dividePolynomial(int f[], int g[]) {
  int dividend[f[0] + 2], divisor[g[0] + 2];
  for (int i = 0; i <= f[0] + 1; ++i) {
    dividend[i] = f[i];
  }

  int quotient[dividend[0] - g[0] + 2];
  // memset(quotient, 0, sizeof(quotient));
  quotient[0] = dividend[0] - g[0];

  for (int i = 1; i <= quotient[0] + 1; ++i) {
    quotient[i] = dividend[i] / g[1];
    for (int j = 1; j <= g[0] + 1; ++j) {
      dividend[i + j - 1] -= quotient[i] * g[j];
    }
    // fprintf(stderr, "dividend: ");
    // Print(dividend, dividend[0] + 2);
    // fprintf(stderr, "quotient: ");
    // Print(quotient, quotient[0] + 2);
  }

  for (int i = 0; i <= quotient[0] + 1; ++i) {
    f[i] = quotient[i];
  }
  g[0] = -1;
  for (int i = quotient[0] + 1; i <= dividend[0] + 1; ++i) {
    if (g[0] == -1 && dividend[i] == 0) {
      continue;
    }
    ++g[0];
    g[g[0] + 1] = dividend[i];
  }

  if (g[0] == -1) {
    g[0] = 0;
    g[1] = 0;
  }
  // for (int i = dividend[dividend[0] + 1]; i > ; --i) {
  //   fprintf(stderr, "%d ", dividend[i]);
  // }
  // fprintf(stderr, "\n");
}

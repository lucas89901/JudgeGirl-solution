#ifdef GP_DEBUG
void Print(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d%c", arr[i], " \n"[i == size - 1]);
  }
}
#endif  // GP_DEBUG

void dividePolynomial(int f[], int g[]) {
  int quotient[f[0] - g[0] + 2];
  quotient[0] = f[0] - g[0];
  for (int i = 1; i <= quotient[0] + 1; ++i) {
    quotient[i] = f[i] / g[1];
    for (int j = 1; j <= g[0] + 1; ++j) {
      f[i + j - 1] -= quotient[i] * g[j];
    }

#ifdef GP_DEBUG
    fprintf(stderr, "dividend: ");
    Print(f, f[0] + 2);
    fprintf(stderr, "quotient: ");
    Print(quotient, quotient[0] + 2);
#endif  // GP_DEBUG
  }

  g[0] = -1;
  for (int i = quotient[0] + 1; i <= f[0] + 1; ++i) {
    if (g[0] == -1 && f[i] == 0) {
      continue;
    }
    ++g[0];
    g[g[0] + 1] = f[i];
  }
  if (g[0] == -1) {
    g[0] = 0;
    g[1] = 0;
  }

  for (int i = 0; i <= quotient[0] + 1; ++i) {
    f[i] = quotient[i];
  }
}

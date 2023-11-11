#include <stdio.h>

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int Solve(int k, int W, int w[], int v[]) {
  if (k < 0 || W <= 0) {
    return 0;
  }
  if (W < w[k]) {
    return Solve(k - 1, W, w, v);
  }
  return Max(Solve(k - 1, W - w[k], w, v) + v[k], Solve(k - 1, W, w, v));
}

int main() {
  int n, W;
  scanf("%d %d", &n, &W);
  int w[n], v[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &w[i], &v[i]);
  }

  printf("%d\n", Solve(n - 1, W, w, v));
  return 0;
}

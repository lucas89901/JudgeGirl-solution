#include <stdio.h>

int Min(int x, int y) {
  if (x < y) {
    return x;
  }
  return y;
}

int main() {
  int k;
  scanf("%d", &k);
  int capacity[k], water[k];
  for (int i = 0; i < k; ++i) {
    scanf("%d", &capacity[i]);
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d", &water[i]);
  }

  int i, j;
  while (scanf("%d%d", &i, &j) != EOF) {
    if (i == k) {
      water[j] = capacity[j];
    } else if (j == k) {
      water[i] = 0;
    } else {
      int poured = Min(water[i], capacity[j] - water[j]);
      water[i] -= poured;
      water[j] += poured;
    }
  }

  for (int i = 0; i < k; ++i) {
    printf("%d%c", water[i], " \n"[i == k - 1]);
  }
  return 0;
}

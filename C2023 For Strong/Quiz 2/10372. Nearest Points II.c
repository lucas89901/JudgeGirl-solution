#include <limits.h>
#include <stdio.h>

int Distance(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  int n;
  scanf("%d", &n);
  int r[n], c[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &r[i], &c[i]);
  }
  int ry, cy;
  scanf("%d%d", &ry, &cy);

  int size = 0;
  int nearest_distance = INT_MAX;
  int index[50000];
  for (int i = 0; i < n; ++i) {
    int distance = Distance(r[i], c[i], ry, cy);
    if (distance < nearest_distance) {
      nearest_distance = distance;
      size = 1;
      index[0] = i;
    } else if (distance == nearest_distance) {
      index[size++] = i;
    }
  }

  for (int i = 0; i < size; ++i) {
    printf("%d\n", index[i]);
  }
  return 0;
}

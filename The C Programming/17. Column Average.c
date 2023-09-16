#include <stdio.h>

int main() {
  int r, c;
  scanf("%d%d", &r, &c);
  int arr[100][100];
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int j = 0; j < c; ++j) {
    int sum = 0;
    for (int i = 0; i < r; ++i) {
      sum += arr[i][j];
    }
    printf("%d\n", sum / r);
  }
  return 0;
}

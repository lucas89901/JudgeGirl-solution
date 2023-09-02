#include <stdio.h>

int main() {
  int N, M, k;
  scanf("%d%d%d", &N, &M, &k);

  // Group 1: M numbers, at row 1, column [1, M]
  // Group 2: N - 1 numbers, at row [2, N], column 1
  // Group 3: M - 1 numbers, at row 2, column [2, M]
  // Group 4: N - 2 numbers, at row [3, N], column 2
  // ...
  int group = 1;
  int total = 0;
  while (1) {
    int group_number_count;
    if (group & 1) {
      group_number_count = M - group / 2;
    } else {
      group_number_count = N - group / 2;
    }
    if (k <= total + group_number_count) {
      break;
    }
    ++group;
    total += group_number_count;
  }

  if (group & 1) {
    printf("%d %d\n", (group + 1) / 2, group / 2 + k - total);
  } else {
    printf("%d %d\n", group / 2 + k - total, group / 2);
  }
  return 0;
}

#include <stdbool.h>
#include <stdio.h>

bool IsInBound(int r, int c, int i, int j) {
  return 0 <= i && i < r && 0 <= j && j < c;
}

int main() {
  int r, c;
  scanf("%d%d", &r, &c);
  int arr[100][100];
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

  const int kOffset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      bool is_answer = true;
      for (int d = 0; d < 4; ++d) {
        if (IsInBound(r, c, i + kOffset[d][0], j + kOffset[d][1]) &&
            arr[i][j] <= arr[i + kOffset[d][0]][j + kOffset[d][1]]) {
          is_answer = false;
          break;
        }
      }

      if (is_answer) {
        printf("%d\n", arr[i][j]);
      }
    }
  }
  return 0;
}

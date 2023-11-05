#include <stdio.h>
#include <string.h>

int main() {
  // right, up, left, down
  const int kOffset[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
  const int kBackwardsDirection[4] = {2, 3, 0, 1};

  int n;
  scanf("%d", &n);
  char grid[n][n];
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i]);
  }

  // Find head of snake.
  int head_r = -1, head_c = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '0') {
        continue;
      }
      int neighbor_count = 0;
      for (int d = 0; d < 4; ++d) {
        int r2 = i + kOffset[d][0], c2 = j + kOffset[d][1];
        if (0 <= r2 && r2 < n && 0 <= c2 && c2 < n && grid[r2][c2] != '0') {
          ++neighbor_count;
        }
      }
      if (neighbor_count != 1) {
        continue;
      }
      if (head_r == -1 || grid[i][j] < grid[head_r][head_c] ||
          (grid[i][j] == grid[head_r][head_c] && i < head_r) ||
          (grid[i][j] == grid[head_r][head_c] && i == head_r && j < head_c)) {
        head_r = i;
        head_c = j;
      }
    }
  }
#ifdef GP_DEBUG
  fprintf(stderr, "%d, %d\n", head_r, head_c);
#endif

  int previous_direction = -1;
  while (1) {
    printf("%c", grid[head_r][head_c]);

    // Find next direction.
    int direction = -1;
    for (int d = 0; d < 4; ++d) {
      if (previous_direction != -1 &&
          d == kBackwardsDirection[previous_direction]) {
        continue;
      }
      int r2 = head_r + kOffset[d][0], c2 = head_c + kOffset[d][1];
      if (0 <= r2 && r2 < n && 0 <= c2 && c2 < n && grid[r2][c2] != '0') {
        direction = d;
      }
    }

    if (direction == -1) {
      break;
    }
    head_r += kOffset[direction][0];
    head_c += kOffset[direction][1];
    previous_direction = direction;
  }
  printf("\n");
  return 0;
}

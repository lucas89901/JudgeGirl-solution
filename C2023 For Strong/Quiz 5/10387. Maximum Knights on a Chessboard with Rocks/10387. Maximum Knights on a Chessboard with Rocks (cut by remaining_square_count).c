#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const int kOffset[8][2] = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1},
                           {-1, 2},  {-2, 1},  {1, 2},  {2, 1}};

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

void Solve(const int n, const int m, int grid[n][m], int r, int c,
           int knight_count, int *answer) {
  if (r == n) {
    *answer = Max(*answer, knight_count);
    return;
  }
  int remaining_square_count = (n - r) * m - c;
  if (knight_count + (remaining_square_count + 1) / 2 <= *answer) {
    return;
  }

  // Don't place a knight on grid[r][c].
  Solve(n, m, grid, r + (c + 1) / m, (c + 1) % m, knight_count, answer);
  if (grid[r][c] != 0) {
    return;
  }

  bool can_place = true;
  for (int d = 0; d < 8; ++d) {
    int r2 = r + kOffset[d][0];
    int c2 = c + kOffset[d][1];
    if (0 <= r2 && r2 < n && 0 <= c2 && c2 < m && grid[r2][c2] == 1) {
      can_place = false;
      break;
    }
  }
  if (can_place) {
    grid[r][c] = 1;
    // Place a knight on grid[r][c].
    Solve(n, m, grid, r + (c + 1) / m, (c + 1) % m, knight_count + 1, answer);
    grid[r][c] = 0;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int grid[n][m];  // 0: empty, 1: knight, 2: rock
  memset(grid, 0, sizeof(grid));
  int r, c;
  while (scanf("%d %d", &r, &c) != EOF) {
    grid[r][c] = 2;
  }

  int answer = 0;
  Solve(n, m, grid, 0, 0, 0, &answer);
  printf("%d\n", answer);
  return 0;
}

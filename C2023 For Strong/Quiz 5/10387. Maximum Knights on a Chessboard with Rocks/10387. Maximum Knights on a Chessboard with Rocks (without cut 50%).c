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

int Solve(const int n, const int m, int grid[n][m], int r, int c,
          int knight_count) {
#ifdef GP_DEBUG
  fprintf(stderr, "r=%d,c=%d,knight_count=%d\n", r, c, knight_count);
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     fprintf(stderr, "%d%c", grid[i][j], " \n"[j == m - 1]);
  //   }
  // }
#endif
  if (r == n) {
    return knight_count;
  }

  int answer = Solve(n, m, grid, r + (c + 1) / m, (c + 1) % m, knight_count);
  if (grid[r][c] != 0) {
    return answer;
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
    answer = Max(answer, Solve(n, m, grid, r + (c + 1) / m, (c + 1) % m,
                               knight_count + 1));
    grid[r][c] = 0;
  }
  return answer;
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

  printf("%d\n", Solve(n, m, grid, 0, 0, 0));
  return 0;
}

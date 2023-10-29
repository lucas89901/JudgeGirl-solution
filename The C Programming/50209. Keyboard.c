#include <stdio.h>
#include <string.h>

int main() {
  const char kKeyboard[3][11] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
  const int kRowSize[3] = {10, 9, 7};
  const int kOffset[6][2] = {{0, 1},  {-1, 1}, {-1, 0},
                             {0, -1}, {1, -1}, {1, 0}};

  char initial;
  scanf("%c", &initial);
  printf("%c\n", initial);

  int row, col;
  for (int i = 0; i < 3; ++i) {
    char *found = strchr(kKeyboard[i], initial);
    if (found) {
      row = i;
      col = found - kKeyboard[i];
      break;
    }
  }

  int direction;
  while (scanf("%d", &direction) != EOF) {
    int next_row = row + kOffset[direction][0];
    int next_col = col + kOffset[direction][1];
    if (0 <= next_row && next_row < 3 && 0 <= next_col &&
        next_col < kRowSize[next_row]) {
      row = next_row;
      col = next_col;
      printf("%c\n", kKeyboard[row][col]);
    }
  }
  return 0;
}

#include <stdio.h>

#include "puzzle.h"

void initPuzzle(Puzzle *puzzle, int grid[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      puzzle->grid[i][j] = grid[i][j];
      if (grid[i][j] == 0) {
        puzzle->space_row = i;
        puzzle->space_column = j;
      }
    }
  }
}

void movePiece(Puzzle *puzzle, char direction) {
  int next_row = puzzle->space_row;
  int next_column = puzzle->space_column;
  switch (direction) {
    case 'U':
      --next_row;
      break;
    case 'D':
      ++next_row;
      break;
    case 'L':
      --next_column;
      break;
    case 'R':
      ++next_column;
      break;
  }

  if (next_row < 0 || next_row >= 4 || next_column < 0 || next_column >= 4) {
    printf("Invalid move\n");
    return;
  }
  puzzle->grid[puzzle->space_row][puzzle->space_column] =
      puzzle->grid[next_row][next_column];
  puzzle->grid[next_row][next_column] = 0;
  puzzle->space_row = next_row;
  puzzle->space_column = next_column;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      printf("%d%c", puzzle->grid[i][j], " \n"[j == 3]);
    }
  }
}

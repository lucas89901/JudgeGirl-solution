#include <stdio.h>

#include "puzzle.h"

void initPuzzle(Puzzle *puzzle, int grid[4][4]);
void movePiece(Puzzle *puzzle, char direction);

int main(void) {
  int grid[4][4] = {0};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  Puzzle puzzle;
  initPuzzle(&puzzle, grid);
  int numMoves;
  scanf("%d", &numMoves);
  char move;
  for (int i = 0; i < numMoves; i++) {
    scanf(" %c", &move);
    movePiece(&puzzle, move);
  }
  return 0;
}

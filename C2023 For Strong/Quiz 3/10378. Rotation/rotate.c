#include "rotate.h"

// No copy, better syntax.
void rotate(int *P[MAX][MAX], int n) {
  int(*array)[MAX] = P[0][0];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      P[i][j] = &array[n - 1 - j][i];
    }
  }
}

// // No copy.
// void rotate(int *P[MAX][MAX], int n) {
//   int *array = P[0][0];
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < n; ++j) {
//       P[i][j] = array + MAX * (n - 1 - j) + i;
//     }
//   }
// }

// // Copy pointer matrix and then move back.
// void rotate(int *P[MAX][MAX], int n) {
//   int *rotated[MAX][MAX];
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < n; ++j) {
//       rotated[i][j] = P[n - 1 - j][i];
//     }
//   }
//
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < n; ++j) {
//       P[i][j] = rotated[i][j];
//     }
//   }
// }

#include "calRectArea.h"

#include <stdio.h>

int Area(int left_x, int left_y, int right_x, int right_y) {
  return (right_x - left_x) * (right_y - left_y);
}

int calRectArea(int N, int M, int *ptrMat, int *ptrLeft[], int *ptrRight[]) {
  int left_x = (ptrLeft[0] - ptrMat) / N;
  int left_y = (ptrLeft[0] - ptrMat) % N;
  int right_x = (ptrRight[0] - ptrMat) / N + 1;
  int right_y = (ptrRight[0] - ptrMat) % N + 1;
#ifdef GP_DEBUG
  fprintf(stderr, "%d,%d,%d,%d\n", left_x, left_y, right_x, right_y);
#endif

  int answer = Area(left_x, left_y, right_x, right_y);
  for (int i = 1; i < M; ++i) {
    int next_left_x = (ptrLeft[i] - ptrMat) / N;
    int next_left_y = (ptrLeft[i] - ptrMat) % N;
    int next_right_x = (ptrRight[i] - ptrMat) / N + 1;
    int next_right_y = (ptrRight[i] - ptrMat) % N + 1;
#ifdef GP_DEBUG
    fprintf(stderr, "%d,%d,%d,%d\n", next_left_x, next_left_y, next_right_x,
            next_right_y);
#endif

    answer += Area(next_left_x, next_left_y, next_right_x, next_right_y) -
              Area(next_left_x, next_left_y, right_x, right_y);
    left_x = next_left_x;
    left_y = next_left_y;
    right_x = next_right_x;
    right_y = next_right_y;
  }
  return answer;
}

#include "Turing_Machine.h"

void Turing_Machine(int *head, int K) {
  int state = 0;
  // [current_state][tape_value]
  const int kWriteTape[3][4] = {{0, 1, 2, 3}, {1, 2, 3, 0}, {2, 3, 0, 1}};
  const int kMoveHead[3][4] = {{1, 1, 1, 1}, {-1, 1, -1, 1}, {0, -1, 1, 0}};
  const int kNextState[3][4] = {{2, 1, 2, 1}, {2, 0, 2, 0}, {1, 0, 1, 0}};
  for (int step = 0; step < K; ++step) {
    int write = kWriteTape[state][*head];
    int *next = head + kMoveHead[state][*head];
    int next_state = kNextState[state][*head];
    *head = write;
    head = next;
    state = next_state;
  }
}

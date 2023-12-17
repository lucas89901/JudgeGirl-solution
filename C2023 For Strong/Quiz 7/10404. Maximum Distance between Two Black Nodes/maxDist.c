#include "maxDist.h"

#include <limits.h>
#include <stdio.h>

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int Helper(Node *node, int *answer) {
  if (node->left) {
    node->farthestLeft = Helper(node->left, answer) + 1;
  } else {
    node->farthestLeft = INT_MIN / 2;
  }
  if (node->right) {
    node->farthestRight = Helper(node->right, answer) + 1;
  } else {
    node->farthestRight = INT_MIN / 2;
  }

  int farthest = Max(node->farthestLeft, node->farthestRight);
  if (!node->color) {
    farthest = Max(farthest, 0);
    *answer = Max(*answer, farthest);
  }
  *answer = Max(*answer, node->farthestLeft + node->farthestRight);
  return farthest;
}

int maxDist(Node *root) {
  int answer = 0;
  Helper(root, &answer);
  return answer;
}

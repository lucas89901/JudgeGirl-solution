#include "construct.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int64_t Sum(int64_t sum[], int l, int r) {
  if (l == 0) {
    return sum[r];
  }
  return sum[r] - sum[l - 1];
}

Node *Build(int T[], int64_t sum[], int l, int r) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->left = NULL;
  node->right = NULL;

  int balancing_point = -1;
  if (r - l + 1 >= 3) {
    int64_t left_torque = 0;
    int64_t right_torque = 0;
    for (int i = l + 1; i <= r; ++i) {
      right_torque += T[i] * (i - l);
    }

    for (int i = l; i <= r; ++i) {
      if (left_torque == right_torque) {
        balancing_point = i;
        break;
      }
      left_torque += Sum(sum, l, i);
      right_torque -= Sum(sum, i + 1, r);
    }
  }

  if (balancing_point == -1) {
    node->value = T[r];
    Node *now = node;
    for (int i = r - 1; i >= l; --i) {
      Node *next = (Node *)malloc(sizeof(Node));
      next->left = NULL;
      next->right = NULL;
      next->value = T[i];
      now->left = next;
      now = next;
    }
  } else {
    node->value = T[balancing_point];
    if (balancing_point != l) {
      node->left = Build(T, sum, l, balancing_point - 1);
    }
    if (balancing_point != r) {
      node->right = Build(T, sum, balancing_point + 1, r);
    }
  }
  return node;
}

Node *ConstructTree(int T[], int N) {
  int64_t sum[N];
  memset(sum, 0, sizeof(sum));
  sum[0] = T[0];
  for (int i = 1; i < N; ++i) {
    sum[i] = sum[i - 1] + T[i];
  }
  return Build(T, sum, 0, N - 1);
}

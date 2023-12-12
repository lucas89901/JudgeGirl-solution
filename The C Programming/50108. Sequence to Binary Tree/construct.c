#include "construct.h"

#include <stdlib.h>

int Compare(const void *lhs2, const void *rhs2) {
  const int *lhs = (const int *)lhs2;
  const int *rhs = (const int *)rhs2;
  // Sort decending.
  return (*lhs < *rhs) - (*lhs > *rhs);
}

int Find(int sequence[], int l, int r, int target) {
  for (int i = l; i <= r; ++i) {
    if (sequence[i] == target) {
      return i;
    }
  }
  return -1;
}

Node *Build(int sequence[], int l, int r) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->left = NULL;
  node->right = NULL;

  if (r - l + 1 < MAXLENGTH) {
    node->value = sequence[r];
    Node *now = node;
    for (int i = r - 1; i >= l; --i) {
      Node *next = (Node *)malloc(sizeof(Node));
      next->value = sequence[i];
      next->left = NULL;
      next->right = NULL;
      now->left = next;
      now = next;
    }
    return node;
  }

  int size = r - l + 1;
  int sorted[size];
  for (int i = 0; i < size; ++i) {
    sorted[i] = sequence[l + i];
  }
  qsort(sorted, size, sizeof(sorted[0]), Compare);

  int pivot_index = Find(sequence, l, r, sorted[MAXLENGTH - 1]);
  node->value = sequence[pivot_index];
  if (pivot_index != l) {
    node->left = Build(sequence, l, pivot_index - 1);
  }
  if (pivot_index != r) {
    node->right = Build(sequence, pivot_index + 1, r);
  }
  return node;
}

Node *ConstructTree(int sequence[], int N) {
  return Build(sequence, 0, N - 1);
}

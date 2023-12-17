#include "buildTree.h"

#include <stdlib.h>

TreeNode *Build(int traverseOrder[], int l, int r) {
  if (l > r) {
    return NULL;
  }

  TreeNode *node = malloc(sizeof(TreeNode));
  node->value = traverseOrder[l];
  node->left = NULL;
  node->right = NULL;
  if (l == r) {
    return node;
  }

  for (int i = l + 1; i <= r - 1; ++i) {
    if (traverseOrder[i] == traverseOrder[l]) {
      node->left = Build(traverseOrder, l + 1, i - 1);
      node->right = Build(traverseOrder, i + 1, r - 1);
      return node;
    }
  }
  return NULL;
}

TreeNode *buildTree(int traverseOrder[MAXARR], int arrSize) {
  return Build(traverseOrder, 0, arrSize - 1);
}

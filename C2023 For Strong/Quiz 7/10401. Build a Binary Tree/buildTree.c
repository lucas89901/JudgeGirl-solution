#include "buildTree.h"

#include <stdlib.h>

TreeNode *buildTree(int traverseOrder[MAXARR], int arrSize) {
  if (arrSize < 1) {
    return NULL;
  }

  TreeNode *node = malloc(sizeof(TreeNode));
  node->value = traverseOrder[0];
  node->left = NULL;
  node->right = NULL;
  if (arrSize == 1) {
    return node;
  }

  for (int i = 1; i < arrSize - 1; ++i) {
    if (traverseOrder[i] == traverseOrder[0]) {
      // 1 to (i - 1)
      node->left = buildTree(traverseOrder + 1, i - 1);
      // (i + 1) to (arrSize - 2)
      node->right = buildTree(traverseOrder + i + 1, arrSize - i - 2);
      return node;
    }
  }
  return NULL;
}

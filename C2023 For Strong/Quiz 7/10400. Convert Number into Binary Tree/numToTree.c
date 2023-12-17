#include "numToTree.h"

#include <stdlib.h>

TreeNode *NewTreeNode(uint64_t num) {
  TreeNode *node = malloc(sizeof(TreeNode));
  node->value = num;
  node->left = NULL;
  node->right = NULL;
  return node;
}

TreeNode *numToTree(uint64_t num, int bitNum) {
  if (num == 0) {
    return NULL;
  }
  TreeNode *node = NewTreeNode(num);
  if (bitNum == 1) {
    return node;
  }
  node->left = numToTree(num >> (bitNum / 2), bitNum / 2);
  node->right = numToTree(num & ((1ULL << (bitNum / 2)) - 1), bitNum / 2);
  return node;
}
